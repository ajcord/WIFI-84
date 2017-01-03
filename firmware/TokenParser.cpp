#include "TokenParser.h"

#define TOKEN_TABLE_SYS_VARS    0
#define TOKEN_TABLE_7E          1
#define TOKEN_TABLE_BB          1
#define TOKEN_TABLE_EF          1
#include "TokenTables.h"

namespace Token {
    int size(Token t) {
        return (t & 0xff00 ? 2 : 1);
    }

    bool isValid(Token t) {
        if (size(t) == 1) {
            // One-byte token
            const char* s = mainTokenTable[t];
            if (s == NULL || s[0] == 0xff) {
                // Token does not exist or is a prefix
                return false;
            } else {
                // Valid one-byte token
                return true;
            }
        } else {
            // Two-byte token
            uint8_t lsb = t & 0xff;
            uint8_t msb = (t & 0xff00) >> 8;
            const char* s = mainTokenTable[lsb];
            if (s == NULL) {
                // Token does not exist
                return false;
            }

            if (s[0] == 0xff) {
                // First byte is a valid prefix
                const char* s2 = ((char**)s)[msb + 1];
                if (s2 == NULL) {
                    // Token does not exist
                    return false;
                } else {
                    // Valid two-byte token
                    return true;
                }
            }
            // First byte is a regular one-byte token, not a prefix
            return false;
        }
    }

    const char* toString(Token t) {
        if (!isValid(t)) {
            return NULL;
        } else {
            if (size(t) == 1) {
                return mainTokenTable[t];
            } else {
                uint8_t lsb = t & 0xff;
                uint8_t msb = (t & 0xff00) >> 8;
                const char* s = mainTokenTable[lsb];
                return ((char**)s)[msb + 1];
            }
        }
    }
}

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
    if (remaining >= 2) {
        // Try the two-byte token starting at _pos
        tok = static_cast<Token::Token>(_data[_pos+1] << 8 | _data[_pos]);
        if (Token::isValid(tok)) {
            _pos += 2;
            return tok;
        }
    }

    tok = static_cast<Token::Token>(_data[_pos]);
    if (Token::isValid(tok)) {
        _pos += 1;
        return tok;
    } else {
        return Token::Invalid;
    }
}

String TokenParser::toString() {
    String str;
    int start_pos = _pos;
    while (_pos < _datalen) {
        Token::Token t = nextToken();
        const char* token_str = Token::toString(t);
        if (token_str != NULL) {
            str.concat(token_str);
        } else {
            str.concat("<ERROR>");
            break;
        }
    }
    _pos = start_pos;
    return str;
}