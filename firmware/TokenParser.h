#pragma once

#include <Arduino.h>

namespace Token {
    enum Token {
        Invalid = 0x00,
        // GetKey = 0xAD,
        Disp = 0xDE,
        Connected = 0x7E06,
        Times = 0x82,
        Div = 0x83,
    };

    int size(Token t);
    bool isValid(Token t);
    const char* toString(Token t);
};

class TokenParser {
public:
    TokenParser(uint8_t* data, int datalen);
    Token::Token nextToken();
    String toString();

private:
    uint8_t* _data;
    int _datalen;
    int _pos;
};