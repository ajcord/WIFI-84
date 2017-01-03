#pragma once

#include <Arduino.h>
#include "TokenParser.h"

class StringBuilder {
public:
    StringBuilder(uint8_t* data);
    bool insert(Token::Token t);
    bool insert(char c);
    bool insert(String s);
    int length();

private:
    uint8_t* _data;
    int _pos;
};
