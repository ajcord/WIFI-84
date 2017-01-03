#pragma once

#include <Arduino.h>
#include "Tokens.h"

class TokenParser {
public:
    TokenParser(uint8_t* data);
    Token::Token nextToken();

private:
    uint8_t* _data;
    int _pos;

    bool isA2ByteTok(uint8_t a);
};
