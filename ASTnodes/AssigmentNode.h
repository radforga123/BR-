//
// Created by Admin on 05.10.2024.
//

#ifndef BR___ASSIGMENTNODE_H
#define BR___ASSIGMENTNODE_H

#include <memory>
#include <string>

#include "ASTNode.h"

class AssigmentNode : public ASTNode{
public:
    std::string variable;
    std::unique_ptr<ASTNode> expression;

    AssigmentNode(const std::string variable, std::unique_ptr<ASTNode> expression)
    :variable(variable), expression(std::move(expression))  {}

    ASTNodeType getType() const override {return ASTNodeType::ASSIGMENT;}
};

#endif //BR___ASSIGMENTNODE_H
