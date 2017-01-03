#include "StringBuilder.h"

StringBuilder::StringBuilder(uint8_t* data) {
    _data = data;
}

bool StringBuilder::insert(Token::Token t) {
    if (t & 0xff00) {
        _data[_pos++] = (t & 0xff00) >> 8;
        _data[_pos++] = (t & 0xff);
    } else {
        _data[_pos++] = (t & 0xff);
    }
    return true;
}

bool StringBuilder::insert(char c) {
    // Reject control characters and 8-bit codes
    if (c < 0x20 || c >= 0x7f) {
        return false;
    }

    // Map basic characters (0-9, A-Z) directly
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z')) {
        return insert((Token::Token) c);
    }

    // Map lowercase letters
    if (c >= 'a' && c <= 'z') {
        char mapped = c - 'a' + (char)Token::a;
        return insert((Token::Token) mapped);
    }

    // Map punctuation
    switch (c) {
        case ' ':
            return insert(Token::Space);
        case '!':
            return insert(Token::ExclPoint);
        case '\"':
            return insert(Token::DoubleQuote);
        case '#':
            return insert(Token::Pound);
        case '$':
            return insert(Token::Dollar);
        case '%':
            return insert(Token::Percent);
        case '&':
            return insert(Token::Ampersand);
        case '\'':
            return insert(Token::SingleQuote);
        case '(':
            return insert(Token::LParen);
        case ')':
            return insert(Token::RParen);
        case '*':
            return insert(Token::Times);
        case '+':
            return insert(Token::Plus);
        case ',':
            return insert(Token::Comma);
        case '-':
            return insert(Token::Minus);
        case '.':
            return insert(Token::Period);
        case '/':
            return insert(Token::Divide);
        case ':':
            return insert(Token::Colon);
        case ';':
            return insert(Token::Semicolon);
        case '<':
            return insert(Token::LessThan);
        case '=':
            return insert(Token::Equals);
        case '>':
            return insert(Token::GreaterThan);
        case '?':
            return insert(Token::QuestionMk);
        case '@':
            return insert(Token::At);
        case '[':
            return insert(Token::LBracket);
        case '\\':
            return insert(Token::Backslash);
        case ']':
            return insert(Token::RBracket);
        case '^':
            return insert(Token::Caret);
        case '_':
            return insert(Token::Underscore);
        case '`':
            return insert(Token::Backtick);
        case '{':
            return insert(Token::LBrace);
        case '|':
            return insert(Token::Pipe);
        case '}':
            return insert(Token::RBrace);
        case '~':
            return insert(Token::Tilde);
    }

    return false; // Should never happen
}

bool StringBuilder::insert(String s) {
    for (int i = 0; i < s.length(); i++) {
        if (!insert(s[i])) {
            return false;
        }
    }
    return true;
}

int StringBuilder::length() {
    return _pos;
}
