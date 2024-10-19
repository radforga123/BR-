//
// Created by Admin on 06.10.2024.
//

#ifndef BR___IFELSENODE_H
#define BR___IFELSENODE_H

#include <memory>

#include "ASTNode.h"

class IfElseNode: public ASTNode{
public:
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> ifBody;
    std::unique_ptr<ASTNode> elseBody;

    IfElseNode(std::unique_ptr<ASTNode> condition,std::unique_ptr<ASTNode> ifBody,std::unique_ptr<ASTNode> elseBody = nullptr)
        : condition(std::move(condition)), ifBody(std::move(ifBody)), elseBody(std::move(elseBody)) {}

    ASTNodeType getType() const override {return ASTNodeType::IF_STATEMENT;}
};
#endif //BR___IFELSENODE_H
