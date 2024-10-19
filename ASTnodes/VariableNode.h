//
// Created by Admin on 05.10.2024.
//

#ifndef BR___VARIABLENODE_H
#define BR___VARIABLENODE_H

#include <string>

#include "ASTNode.h"


class VariableNode:public ASTNode{
public:
    std::string name;

    VariableNode(const std::string& name) : name(name) {}
    ASTNodeType getType() const override {return ASTNodeType::VARIABLE;}
};

#endif //BR___VARIABLENODE_H
