#include "StringBuilder.h"

StringBuilder::StringBuilder(uint8_t* data) {
    _data = data;
    _pos = 0;
    _tokenLen = 0;
}

bool StringBuilder::append(Token::Token t) {
    if (t & 0xff00) {
        _data[_pos++] = (t & 0xff00) >> 8;
        _data[_pos++] = (t & 0xff);
    } else {
        _data[_pos++] = (t & 0xff);
    }
    _tokenLen += 1;
    return true;
}

bool StringBuilder::append(char c) {
    // Reject control characters and 8-bit codes
    if (c < 0x20 || c >= 0x7f) {
        return false;
    }

    // Map basic characters (0-9, A-Z) directly
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z')) {
        return append((Token::Token) c);
    }

    // Map lowercase letters
    if (c >= 'a' && c <= 'z') {
        char mapped = c - 'a' + (char)Token::a;
        return append((Token::Token) mapped);
    }

    // Map punctuation
    switch (c) {
        case ' ':
            return append(Token::Space);
        case '!':
            return append(Token::ExclPoint);
        case '\"':
            return append(Token::DoubleQuote);
        case '#':
            return append(Token::Pound);
        case '$':
            return append(Token::Dollar);
        case '%':
            return append(Token::Percent);
        case '&':
            return append(Token::Ampersand);
        case '\'':
            return append(Token::SingleQuote);
        case '(':
            return append(Token::LParen);
        case ')':
            return append(Token::RParen);
        case '*':
            return append(Token::Times);
        case '+':
            return append(Token::Plus);
        case ',':
            return append(Token::Comma);
        case '-':
            return append(Token::Minus);
        case '.':
            return append(Token::Period);
        case '/':
            return append(Token::Divide);
        case ':':
            return append(Token::Colon);
        case ';':
            return append(Token::Semicolon);
        case '<':
            return append(Token::LessThan);
        case '=':
            return append(Token::Equals);
        case '>':
            return append(Token::GreaterThan);
        case '?':
            return append(Token::QuestionMk);
        case '@':
            return append(Token::At);
        case '[':
            return append(Token::LBracket);
        case '\\':
            return append(Token::Backslash);
        case ']':
            return append(Token::RBracket);
        case '^':
            return append(Token::Caret);
        case '_':
            return append(Token::Underscore);
        case '`':
            return append(Token::Backtick);
        case '{':
            return append(Token::LBrace);
        case '|':
            return append(Token::Pipe);
        case '}':
            return append(Token::RBrace);
        case '~':
            return append(Token::Tilde);
    }

    return false; // Should never happen
}

bool StringBuilder::append(String s) {
    for (int i = 0; i < s.length(); i++) {
        if (!append(s[i])) {
            return false;
        }
    }
    return true;
}

int StringBuilder::length() {
    return _pos;
}

int StringBuilder::tokenLength() {
    return _tokenLen;
}
