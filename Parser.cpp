//
// Created by Admin on 06.10.2024.
//

#include "Parser.h"
#include "TokenType.h"
#include "ASTnodes/BinaryOpNode.h"
#include "ASTnodes/NumberNode.h"
#include "ASTnodes/VariableNode.h"
#include "ASTnodes/AssigmentNode.h"
#include "ASTnodes/IfElseNode.h"
#include "ASTnodes/WhileNode.h"

std::unique_ptr<ASTNode> Parser::parseExpression() {
    return parseComparison();
}

std::unique_ptr<ASTNode> Parser::parseComparison(){
    auto node = parseAddSub();

    if (currentToken().type == TokenType::COMPARE){
        char op = currentToken().value[0];
        if (currentToken().value[1] == '='){
            switch (currentToken().value[0]) {
                case '<':
                    op = 'A';
                    break;
                case '>':
                    op='R';
                    break;
                case '!':
                    op='F';
                    break;
                case '=':
                    op='D';
                    break;
            }
        }

        nextToken();

        node = std::make_unique<BinaryOpNode>(op, std::move(node), parseAddSub());
    }
    return node;
}

std::unique_ptr<ASTNode> Parser::parseAddSub() {
    auto node = parseMulDiv();
    while (currentToken().type == TokenType::OPERATOR && (currentToken().value == "+" || currentToken().value == "-")){
        char op = currentToken().value[0];
        nextToken();
        node = std::make_unique<BinaryOpNode>(op, std::move(node), parseMulDiv());
    }

    return node;
}

std::unique_ptr<ASTNode> Parser::parseMulDiv() {
    auto node = parsePrimary();

    while (currentToken().type == TokenType::OPERATOR && (currentToken().value == "*" || currentToken().value == "/")){
        char op = currentToken().value[0];
        nextToken();
        node= std::make_unique<BinaryOpNode>(op, std::move(node), parsePrimary());
    }

    return node;
}

std::unique_ptr<ASTNode> Parser::parsePrimary() {
    if (currentToken().type == TokenType::NUMBER){
        int value = std::stoi(currentToken().value);
        nextToken();
        return std::make_unique<NumberNode>(value);
    }
    else if (currentToken().type == TokenType::IDENTIFIER){
        std::string name = currentToken().value;
        nextToken();
        return std::make_unique<VariableNode>(name);
    }
    else if(currentToken().value == ")"){
        nextToken();
        auto node = parseExpression();
        if (currentToken().value == "("){
            nextToken();
        }
        return node;
    }
    return nullptr;
}

std::unique_ptr<ASTNode> Parser::parseAssigment() {
    std::string variable = currentToken().value;
    nextToken();

    if (currentToken().value == "="){
        nextToken();
        auto expression = parseExpression();
        return std::make_unique<AssigmentNode>(variable, std::move(expression));
    }
    return nullptr;
}

std::unique_ptr<ASTNode> Parser::parseIfElse(){
    nextToken();
    nextToken();
    auto condition = parseExpression();
    nextToken();
    auto ifBody = parseBlock();

    std::unique_ptr<ASTNode> elseBody = nullptr;
    if (currentToken().type == TokenType::KEYWORD_ELSE){
        nextToken();
        elseBody = parseBlock();
    }

    return std::make_unique<IfElseNode>(std::move(condition), std::move(ifBody), std::move(elseBody));
}

std::unique_ptr<ASTNode> Parser::parseWhile(){
    nextToken();
    nextToken();
    auto condition = parseExpression();
    nextToken();
    auto body = parseBlock();

    return std::make_unique<WhileNode>(std::move(condition), std::move(body));
}

std::unique_ptr<ASTNode> Parser::parseBlock(){
    nextToken();
    auto node = parse();
    nextToken();
    return node;
}


std::unique_ptr<ASTNode> Parser::parse() {
    if (currentToken().type == TokenType::KEYWORD_IF) {
        return parseIfElse();
    } else if (currentToken().type == TokenType::KEYWORD_WHILE) {
        return parseWhile();
    }
    return parseAssigment();


}

std::vector<std::unique_ptr<ASTNode>> Parser::parseProgram() {
    std::vector<std::unique_ptr<ASTNode>> nodes;

    // Парсим выражения пока не достигнем конца файла (EOF)
    while (currentToken().type != TokenType::END_OF_STATEMENT && currentToken().type != TokenType::CLOSE_BRACE) {
        auto node = parse(); // Парсим одно выражение
        if (node) {
            nodes.push_back(std::move(node));
        }

        // Пропускаем символ ";", если он встречается
        if ((currentToken().type == TokenType::END_OF_STATEMENT || currentToken().type == TokenType::CLOSE_BRACE )&& pos<tokens.size()-1 ) {
            nextToken(); // Пропускаем ";"
        } else if(pos >= tokens.size()){
            break;
        }
    }

    return nodes;
}