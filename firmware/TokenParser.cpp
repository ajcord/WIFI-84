#include "TokenParser.h"

TokenParser::TokenParser(uint8_t* data) {
    _data = data;
}

Token::Token TokenParser::nextToken() {
    Token::Token tok;
    if (isA2ByteTok(_data[_pos])) {
        tok = (Token::Token)(_data[_pos+1] << 8 | _data[_pos]);
        _pos += 2;
        return tok;
    } else {
        tok = (Token::Token)(_data[_pos]);
        _pos += 1;
        return tok;
    }
}

enum {
    tVarMat                 = 0x5c,
    tVarLst                 = 0x5d,
    tVarEqu                 = 0x5e,
    tVarPict                = 0x60,
    tVarGDB                 = 0x61,
    tVarOut                 = 0x62,
    tVarSys                 = 0x63,
    tGFormat                = 0x7e,
    tVarStrng               = 0xaa,
    t2ByteTok               = 0xbb,
    tNew2ByteTok            = 0xef,
} twoByteTokenPrefixes;

bool TokenParser::isA2ByteTok(uint8_t a) {
    return (
        a == tVarMat        ||
        a == tVarLst        ||
        a == tVarEqu        ||
        a == tVarPict       ||
        a == tVarGDB        ||
        a == tVarOut        ||
        a == tVarSys        ||
        a == tGFormat       ||
        a == tVarStrng      ||
        a == t2ByteTok      ||
        a == tNew2ByteTok
    );
}
