//
// Created by Admin on 05.10.2024.
//

#ifndef BR___BINARYOPNODE_H
#define BR___BINARYOPNODE_H

#include <memory>

#include "ASTNode.h"

class BinaryOpNode:public ASTNode{
public:
    char op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
    BinaryOpNode(char op, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
    :op(op), left(std::move(left)),right(std::move(right)) {}

    ASTNodeType getType() const override {return ASTNodeType::BINARY_OP;}
};

#endif //BR___BINARYOPNODE_H
