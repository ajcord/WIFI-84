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
};

class TokenParser {
public:
    TokenParser(uint8_t* data);
    Token::Token nextToken();

private:
    uint8_t* _data;
    int _pos;

    bool isA2ByteTok(uint8_t c);
};
