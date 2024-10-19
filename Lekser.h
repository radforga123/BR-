//
// Created by Admin on 03.10.2024.
//

#ifndef BR___LEKSER_H
#define BR___LEKSER_H
#include <string>
#include <cctype>
#include <vector>
#include "Token.h"

class Lekser {
public:


// Структура для хранения токена



    std::vector<Token> lexer(const std::string& code);
private:

};


#endif //BR___LEKSER_H
