#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <CBL2.h>
#include <TIVar.h>
#include "TokenParser.h"
#include "Tokens.h"

CBL2 cbl;

const int tipPin = 0;
const int ringPin = 2;

const int maxDataLen = 512;
uint8_t header[16];
uint8_t data[maxDataLen];

String pendingString;
long pendingReal;

WiFiClient tcpClient;
WiFiUDP udpClient;

// For artificial UDP connection management
bool isUDP;
String udpAddr;
uint16_t udpPort;

void setup() {
    Serial.begin(115200);
    cbl.setLines(tipPin, ringPin);
    cbl.resetLines();
    cbl.setupCallbacks(header, data, maxDataLen, onReceived, onRequest);
    Serial.println("Ready");
}

void loop() {
    cbl.eventLoopTick();
}

// Called when a variable is received from the calculator
int onReceived(uint8_t type, enum Endpoint model, int datalen) {
    Serial.println("Received variable of type " + type);
    if (type != VarTypes82::VarString) {
        // Require strings only
        Serial.println("Rejected");
        return -1;
    }

    String params = TIVar::strVarToString8x(data, model);
    if (params.endsWith(")")) {
        params = params.substring(1, params.length() - 1);
    } else {
        params = params.substring(1);
    }

    TokenParser parser(&data[2]);
    Token::Token tok = parser.nextToken();
    switch (tok) {
        /**
         * Get Wi-Fi connection status.
         * 
         * Syntax: Connected
         * 
         * Returns one of the following real values in A:
         * - 0 if connected
         * - 1 if disconnected
         * - 2 if SSID cannot be reached
         * - 3 if password is incorrect
         * - 4 if in between states
         */
        case Token::Connected:
            pendingReal = -1;
            switch (WiFi.status()) {
                case WL_CONNECTED:      pendingReal = 0; break;
                case WL_DISCONNECTED:   pendingReal = 1; break;
                case WL_NO_SSID_AVAIL:  pendingReal = 2; break;
                case WL_CONNECT_FAILED: pendingReal = 3; break;
                case WL_IDLE_STATUS:    pendingReal = 4; break;
            }
            Serial.println("Connection status: " + pendingReal);
            break;

        /**
         * Get a list of nearby access points.
         * 
         * Syntax: Menu()
         * 
         * Returns a CSV of access points in Str1, in the following format:
         * ssid1,encryption1,rssi1/ssid2,encryption2,rssi2/...
         * - ssid is the name of the network
         * - encryption is an integer enumeration of various security types:
         *   - 0 = open
         *   - 1 = WEP
         *   - 2 = WPA
         *   - 3 = WPA2
         *   - 4 = WPA/WPA2 mixed
         * - rssi is the signal strength in dBm
         */
        case Token::Menu: {
            int num = WiFi.scanNetworks();
            pendingString = "";
            for (int i = 0; i < num; i++) {
                int encryption = -1;
                switch (WiFi.encryptionType(i)) {
                    case ENC_TYPE_NONE: encryption = 0; break;
                    case ENC_TYPE_WEP:  encryption = 1; break;
                    case ENC_TYPE_TKIP: encryption = 2; break; // WPA
                    case ENC_TYPE_CCMP: encryption = 3; break; // WPA2
                    case ENC_TYPE_AUTO: encryption = 4; break; // WPA/WPA2
                }
                pendingString.concat(
                    WiFi.SSID(i) + ',' + encryption + ',' + WiFi.RSSI(i) + '/'
                );
            }
            Serial.println("AP list: " + pendingString);
            break;
        }

        /**
         * Connect to an access point.
         * 
         * Syntax: Select(ssid)
         * Alternate: Select(ssid,password)
         * 
         * Returns nothing. Use "Connected" to get the result.
         */
        case Token::Select: {
            int commaIndex = params.indexOf(",");
            if (commaIndex != -1) {
                String ssid = params.substring(0, commaIndex);
                String pass = params.substring(commaIndex + 1);
                WiFi.begin(ssid.c_str(), pass.c_str());
            } else {
                WiFi.begin(params.c_str());
            }
            break;
        }

        /**
         * Connect to a TCP or UDP server.
         * 
         * Syntax: For(type,addr,port)
         * Where:
         * - type = 0 for UDP, 1 for TCP
         * - addr = remote IP address or hostname
         * - port = remote port
         * 
         * Returns A = 1 on success or 0 on failure.
         * Note that UDP connections are artificial and always succeed unless
         * no sockets are available.
         * 
         * TODO: eventually would like to support multiple connections,
         * like sockets. Shouldn't be that bad with an array of WiFiClients
         * and a Berkeley-style interface.
         */
        case Token::For: {
            int firstCommaIndex = params.indexOf(",");
            int lastCommaIndex = params.lastIndexOf(",");
            if (firstCommaIndex == lastCommaIndex) {
                break;
            }
            int type = params.substring(0, firstCommaIndex).toInt();
            String addr = params.substring(firstCommaIndex + 1, lastCommaIndex);
            uint16_t port = params.substring(lastCommaIndex + 1).toInt();
            if (type) {
                isUDP = false;
                pendingReal = tcpClient.connect(addr.c_str(), port);
            } else {
                udpAddr = addr;
                udpPort = port;
                // For simplicity, use the remote port as the local port too
                pendingReal = udpClient.begin(port);
                isUDP = pendingReal;
            }
        }

        /**
         * Closes a connection.
         * 
         * Syntax: Stop
         * 
         * Returns nothing.
         */
        case Token::Stop: {
            if (isUDP) {
                udpClient.stop();
            } else {
                tcpClient.stop();
            }
        }

        /**
         * Transmit data over the current connection.
         * 
         * Syntax: DS<(data)
         * Where data is the text to send.
         * 
         * Returns nothing.
         */
        case Token::DS: {
            if (isUDP) {
                udpClient.beginPacket(udpAddr.c_str(), udpPort);
                udpClient.write(params.c_str(), params.length());
                udpClient.endPacket();
            } else {
                tcpClient.print(params);
            }
        }

        /**
         * Receive data from the current connection.
         * 
         * Syntax: IS>()
         * 
         * Returns the data received, if any, in Str1.
         */
         case Token::IS: {
            if (isUDP) {
                int len = udpClient.parsePacket();
                uint8_t* buf = (uint8_t*)malloc(len);
                udpClient.read(buf, len);
                pendingString = String((const char*)buf);
                // Only valid if String constructor makes a copy.
                // TODO: verify this.
                free(buf);
            } else {
                pendingString = "";
                while (tcpClient.available()) {
                    pendingString.concat(tcpClient.read());
                }
            }
         }
    }
    return 0;
}

// Called when the calculator requests a variable
int onRequest(uint8_t type, enum Endpoint model, int* headerlen, int* datalen,
              data_callback* data_callback) {
    Serial.println("Got request for variable of type " + type);
    switch(type) {
        case VarTypes82::VarString: {
            int rval = TIVar::stringToStrVar8x(pendingString, data, model);
            if (rval < 0) {
                return -1;
            }
            *datalen = rval;

            memset(header, 0, sizeof(header));
            TIVar::intToSizeWord(rval, header);
            header[2] = type; // Variable type
            header[3] = 0xAA; // Variable name (Str1)
            header[4] = 0x00; // ^
            *headerlen = 13;
            Serial.println("Responding with \"" + pendingString + "\"");
            return 0;
        }
        case VarTypes82::VarReal: {
            int rval = TIVar::longToReal8x(pendingReal, data, model);
            if (rval < 0) {
                return -1;
            }
            *datalen = rval;

            memset(header, 0, sizeof(header));
            TIVar::intToSizeWord(rval, header);
            header[2] = type; // Variable type
            header[3] = 0x41; // Variable name (A)
            *headerlen = 13;
            Serial.println("Responding with " + pendingReal);
            return 0;
        }
        default:
            *headerlen = 0;
            *datalen = 0;
            Serial.println("Rejected");
            return -1;
    }
}
