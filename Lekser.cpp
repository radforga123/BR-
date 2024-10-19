//
// Created by Admin on 03.10.2024.
//

#include "Lekser.h"
#include "Token.h"
#include "TokenType.h"
// Лексер для преобразования строки в список токенов
std::vector<Token> Lekser::lexer(const std::string &code){
    std::vector<Token> tokens;
    size_t i = 0;

    while (i < code.size()) {
        char currentChar = code[i];

        // Пропускаем пробелы
        if (isspace(currentChar)) {
            i++;
            continue;
        }

        // Числа
        if (isdigit(currentChar)) {
            std::string number;
            while (i < code.size() && isdigit(code[i])) {
                number += code[i];
                i++;
            }
            tokens.push_back(Token(TokenType::NUMBER, number));
            continue;
        }

        // Идентификаторы (переменные)
        if (isalpha(currentChar)) {
            std::string identifier;
            while (i < code.size() && (isalnum(code[i]) || code[i] == '_')) {
                identifier += code[i];
                i++;
            }

            // Проверка на ключевые слова
            if (identifier == "if") {
                tokens.push_back(Token(TokenType::KEYWORD_IF, identifier));
            } else if (identifier == "else") {
                tokens.push_back(Token(TokenType::KEYWORD_ELSE, identifier));
            } else if (identifier == "while") {
                tokens.push_back(Token(TokenType::KEYWORD_WHILE, identifier));
            } else {
                tokens.push_back(Token(TokenType::IDENTIFIER, identifier));
            }
            continue;
        }

        // Операторы сравнения
        if (currentChar == '=' && i + 1 < code.size() && code[i + 1] == '=') {
            tokens.push_back(Token(TokenType::COMPARE, "=="));
            i += 2;
            continue;
        }
        if (currentChar == '!' && i + 1 < code.size() && code[i + 1] == '=') {
            tokens.push_back(Token(TokenType::COMPARE, "!="));
            i += 2;
            continue;
        }
        if (currentChar == '<' && i + 1 < code.size() && code[i + 1] == '=') {
            tokens.push_back(Token(TokenType::COMPARE, "<="));
            i += 2;
            continue;
        }
        if (currentChar == '>' && i + 1 < code.size() && code[i + 1] == '=') {
            tokens.push_back(Token(TokenType::COMPARE, ">="));
            i += 2;
            continue;
        }

        // Операторы
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            tokens.push_back(Token(TokenType::OPERATOR, std::string(1, currentChar)));
            i++;
            continue;
        }
        if (currentChar == '<' || currentChar == '>') {
            tokens.push_back(Token(TokenType::COMPARE, std::string(1, currentChar)));
            i++;
            continue;
        }
        // Оператор присваивания
        if (currentChar == '=') {
            tokens.push_back(Token(TokenType::ASSIGNMENT, "="));
            i++;
            continue;
        }

        // Точка с запятой (конец оператора)
        if (currentChar == ';') {
            tokens.push_back(Token(TokenType::END_OF_STATEMENT, ";"));
            i++;
            continue;
        }

        // Открывающая скобка (
        if (currentChar == '(') {
            tokens.push_back(Token(TokenType::PAREN_OPEN, "("));
            i++;
            continue;
        }

        // Закрывающая скобка )
        if (currentChar == ')') {
            tokens.push_back(Token(TokenType::PAREN_CLOSE, ")"));
            i++;
            continue;
        }
        if (currentChar == '}'){
            tokens.push_back(Token(TokenType::CLOSE_BRACE, "}"));
            i++;
            continue;
        }

        // Если символ не распознан
        tokens.push_back(Token(TokenType::UNKNOWN, std::string(1, currentChar)));
        i++;
    }

    return tokens;
}