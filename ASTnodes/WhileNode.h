//
// Created by Admin on 07.10.2024.
//

#ifndef BR___WHILENODE_H
#define BR___WHILENODE_H

#include <memory>

#include "ASTNode.h"

class WhileNode: public ASTNode{
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> body;

    WhileNode(std::unique_ptr<ASTNode> condition,std::unique_ptr<ASTNode> body)
        : condition(std::move(condition)), body(std::move(body)) {}

    ASTNodeType getType() const override {return ASTNodeType::WHILE_STATEMENT;}
};

#endif //BR___WHILENODE_H
