#include "TokenParser.h"

TokenParser::TokenParser(uint8_t* data, int datalen) {
    _data = data;
    _datalen = datalen;
}

Token::Token TokenParser::nextToken() {
    int remaining = _datalen - _pos;
    if (remaining <= 0) {
        return Token::Invalid;
    }

    Token::Token tok;
    if (isA2ByteTok(_data[_pos])) {
        tok = static_cast<Token::Token>(_data[_pos+1] << 8 | _data[_pos]);
        _pos += 2;
        return tok;
    } else {
        tok = static_cast<Token::Token>(_data[_pos]);
        _pos += 1;
        return tok;
    }
}

bool TokenParser::isA2ByteTok(uint8_t a) {
    return (
        a == 0x5c ||
        a == 0x5d ||
        a == 0x5e ||
        a == 0x60 ||
        a == 0x61 ||
        a == 0x62 ||
        a == 0x63 ||
        a == 0x7e ||
        a == 0xaa ||
        a == 0xbb ||
        a == 0xef
    );
}
