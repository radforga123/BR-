//
// Created by Admin on 06.10.2024.
//

#ifndef BR___PARSER_H
#define BR___PARSER_H

#include <vector>
#include <memory>

#include "Lekser.h"
#include "Token.h"
#include "ASTnodes/ASTNode.h"

class Parser {
private:
    const std::vector<Token>& tokens;
    size_t pos = 0;

    const Token& currentToken() const {return tokens[pos];}

    void nextToken() {++pos;}
public:
    Parser(const std::vector<Token>& tokens) :tokens(tokens) {}

    std::unique_ptr<ASTNode> parseExpression();

    std::unique_ptr<ASTNode> parseComparison();

    std::unique_ptr<ASTNode> parseAddSub();

    std::unique_ptr<ASTNode> parseMulDiv();

    std::unique_ptr<ASTNode> parsePrimary();

    std::unique_ptr<ASTNode> parseAssigment();

    std::unique_ptr<ASTNode> parseIfElse();

    std::unique_ptr<ASTNode> parseWhile();

    std::unique_ptr<ASTNode> parseBlock();

    std::unique_ptr<ASTNode> parse();

    std::vector<std::unique_ptr<ASTNode>> parseProgram();
};


#endif //BR___PARSER_H
