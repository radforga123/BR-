//
// Created by Admin on 06.10.2024.
//

#ifndef BR___TOKENTYPE_H
#define BR___TOKENTYPE_H

enum class TokenType {
    NUMBER,
    IDENTIFIER,
    OPERATOR,
    PAREN_OPEN,
    PAREN_CLOSE,
    ASSIGNMENT,
    END_OF_STATEMENT,
    KEYWORD_IF,
    KEYWORD_ELSE,
    KEYWORD_WHILE,
    COMPARE,
    CLOSE_BRACE,
    UNKNOWN
};


#endif //BR___TOKENTYPE_H
