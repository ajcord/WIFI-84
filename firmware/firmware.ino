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
    cbl.setLines(tipPin, ringPin);
    cbl.resetLines();
    cbl.setupCallbacks(header, data, maxDataLen, onReceived, onRequest);
}

void loop() {
    cbl.eventLoopTick();
}

// Called when a variable is received from the calculator
int onReceived(uint8_t type, enum Endpoint model, int datalen) {
    if (type != VarTypes82::VarString) {
        // Require strings only
        return -1;
    }

    TokenParser parser(data);
    Token::Token tok = parser.nextToken();
    if (tok == Token::Connected) {
        pendingReal = (WiFi.status() == WL_CONNECTED);
    } else if (tok == Token::Disp) {
        int num = WiFi.scanNetworks();
        // Build a CSV of network info.
        // Columns are separated by commas and rows by slashes.
        pendingString = "";
        for (int i = 0; i < num; i++) {
            int needPassword = (WiFi.encryptionType(i) != ENC_TYPE_NONE);
            pendingString.concat(
                WiFi.SSID(i) + ',' + needPassword + ',' + WiFi.RSSI(i) + '/'
            );
        }
    }
    return 0;
}

// Called when the calculator requests a variable
int onRequest(uint8_t type, enum Endpoint model, int* headerlen, int* datalen,
              data_callback* data_callback) {
    switch(type) {
        case VarTypes82::VarString: {
            int rval = TIVar::stringToStrVar8x(pendingString, data, model);
            if (rval < 0) {
                return -1;
            }
            *datalen = rval;

            memset(header, 0, sizeof(header));
            TIVar::intToSizeWord(rval, header);
            header[2] = VarTypes82::VarString; // Variable type
            header[3] = 0xAA; // Variable name (Str1)
            header[4] = 0x00; // ^
            *headerlen = 13;
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
            header[2] = VarTypes82::VarReal; // Variable type
            header[3] = 'A'; // Variable name (A)
            *headerlen = 13;
            return 0;
        }
        default:
            *headerlen = 0;
            *datalen = 0;
            return -1;
    }
}
