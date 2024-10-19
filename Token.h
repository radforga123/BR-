//
// Created by Admin on 06.10.2024.
//

#ifndef BR___TOKEN_H
#define BR___TOKEN_H

#include "TokenType.h"
struct Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};
#endif //BR___TOKEN_H
