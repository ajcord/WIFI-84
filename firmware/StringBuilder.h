#pragma once

#include <Arduino.h>
#include "TokenParser.h"

class StringBuilder {
public:
    StringBuilder(uint8_t* data, int maxlen);
    bool append(Token::Token t);
    bool append(char c);
    bool append(String s);
    int length();
    int tokenLength();

private:
    uint8_t* _data;
    int _maxlen;
    int _pos;
    int _tokenLen;
};
