#pragma once

#include <Arduino.h>

namespace Token {
    enum Token {
        Invalid     = 0x00,
        LBracket    = 0x06,
        RBracket    = 0x07,
        LBrace      = 0x08,
        RBrace      = 0x09,
        LParen      = 0x10,
        RParen      = 0x11,
        Space       = 0x29,
        DoubleQuote = 0x2a,
        Comma       = 0x2b,
        ExclPoint   = 0x2d,
        Period      = 0x3a,
        Colon       = 0x3e,
        Equals      = 0x6a,
        LessThan    = 0x6b,
        GreaterThan = 0x6c,
        Plus        = 0x70,
        Minus       = 0x71,
        Connected   = 0x7e06,
        Times       = 0x82,
        Divide      = 0x83,
        SingleQuote = 0xae,
        QuestionMk  = 0xaf,
        a           = 0xbbb0,
        Tilde       = 0xbbcf,
        At          = 0xbbd1,
        Pound       = 0xbbd2,
        Dollar      = 0xbbd3,
        Ampersand   = 0xbbd4,
        Backtick    = 0xbbd5,
        Semicolon   = 0xbbd6,
        Backslash   = 0xbbd7,
        Pipe        = 0xbbd8,
        Underscore  = 0xbbd9,
        Percent     = 0xbbd9,
        Disp        = 0xde,
        Caret       = 0xf0,
    };
};

class TokenParser {
public:
    TokenParser(uint8_t* data);
    Token::Token nextToken();

private:
    uint8_t* _data;
    int _pos;

    bool isA2ByteTok(uint8_t a);
};
