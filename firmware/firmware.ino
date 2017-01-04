#include <ESP8266WiFi.h>
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

    TokenParser parser(&data[2]);
    Token::Token tok = parser.nextToken();
    switch (tok) {
        case Token::Connected:
            pendingReal = (WiFi.status() == WL_CONNECTED);
            Serial.println("Connection status: " + pendingReal);
            break;
        case Token::Menu: {
            int num = WiFi.scanNetworks();
            // Build a CSV of network info.
            // Columns are separated by commas and rows by slashes.
            pendingString = "";
            for (int i = 0; i < num; i++) {
                int encryption;
                switch (WiFi.encryptionType(i)) {
                    case ENC_TYPE_NONE: encryption = 0; break;
                    case ENC_TYPE_WEP:  encryption = 1; break;
                    case ENC_TYPE_TKIP: encryption = 2; break; // WPA
                    case ENC_TYPE_CCMP: encryption = 3; break; // WPA2
                    case ENC_TYPE_AUTO: encryption = 4; break; // WPA/WPA2
                    default:            encryption = -1; break;
                }
                pendingString.concat(
                    WiFi.SSID(i) + ',' + encryption + ',' + WiFi.RSSI(i) + '/'
                );
            }
            Serial.println("AP list: " + pendingString);
            break;
        }
        case Token::Select: {
            String s = TIVar::strVarToString8x(data, model);
            int commaIndex = s.indexOf(",");
            if (commaIndex != -1) {
                String ssid = WiFi.SSID(s.substring(1, commaIndex).toInt());
                String pass = s.substring(commaIndex + 1);
                WiFi.begin(ssid.c_str(), pass.c_str());
            } else {
                String ssid = WiFi.SSID(s.substring(1).toInt());
                WiFi.begin(ssid.c_str());
            }
            break;
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
