//
// Created by Admin on 05.10.2024.
//

#ifndef BR___NUMBERNODE_H
#define BR___NUMBERNODE_H
#include "ASTNode.h"

class NumberNode: public ASTNode {
public:
    int value;

    NumberNode(int value) : value(value) {}

    ASTNodeType getType() const override {return ASTNodeType::NUMBER;}
};


#endif //BR___NUMBERNODE_H
