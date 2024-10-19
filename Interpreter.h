//
// Created by Admin on 12.10.2024.
//

#ifndef BR___INTERPRETER_H
#define BR___INTERPRETER_H

#include <memory>
#include <unordered_map>
#include <stdexcept>

#include "ASTnodes/ASTNode.h"
#include "ASTnodes/BinaryOpNode.h"
#include "ASTnodes/NumberNode.h"
#include "ASTnodes/VariableNode.h"
#include "ASTnodes/AssigmentNode.h"
#include "ASTnodes/IfElseNode.h"
#include "ASTnodes/WhileNode.h"

class Interpreter {
public:

    std::unordered_map<std::string, int> variables;

    int interpreter(const std::unique_ptr<ASTNode>& node){
        switch (node->getType()) {
            case ASTNodeType::NUMBER:
                return evaluateNumber(static_cast<NumberNode*>(node.get()));
            case ASTNodeType::VARIABLE:
                return evaluateVariable(static_cast<VariableNode*>(node.get()));
            case ASTNodeType::BINARY_OP:
                return evaluateBinaryOp(static_cast<BinaryOpNode*>(node.get()));
            case ASTNodeType::ASSIGMENT:
                return evaluateAssigment(static_cast<AssigmentNode*>(node.get()));
            case ASTNodeType::IF_STATEMENT:
                return evaluateIfElse(static_cast<IfElseNode*>(node.get()));
            case ASTNodeType::WHILE_STATEMENT:
                return evaluateWhile(static_cast<WhileNode*>(node.get()));
            default:
                throw std::runtime_error("Unknown AST node type.");
        }
    }

private:
    int evaluateNumber(NumberNode* node){
        return node->value;
    }

    int evaluateVariable(VariableNode* node){
        if (variables.find(node->name) == variables.end()){
            throw std::runtime_error("Undefined variables " + node->name);
        }
        return variables[node->name];
    }
    int evaluateAssigment(AssigmentNode* node){
        int value = interpreter(node->expression);
        variables[node->variable] = value;
        return value;
    }

    int evaluateBinaryOp(BinaryOpNode* node){
        int left = interpreter(node->left);
        int right = interpreter(node->right);
        switch (node->op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                if (right == 0) {
                    throw std::runtime_error("Division by zero.");
                }
                return left / right;
            case '<':
                return left < right;
            case '>':
                return left > right;
            case 'R':
                return left >= right;
            case 'A':
                return left <= right;
            case 'D':
                return left == right;
            case 'F':
                return left != right;
            default:
                throw std::runtime_error("Unknown operator.");
        }
    }

    int evaluateIfElse(IfElseNode* node){
        int condition = interpreter(node -> condition);
        if (condition){
            return interpreter(node->ifBody);
        }
        else if(node -> elseBody){
            return interpreter(node->elseBody);
        }
        return 0;
    }

    int evaluateWhile(WhileNode* node){
        while (interpreter(node->condition)){
            interpreter(node -> body);
        }
        return 0;
    }
};


#endif //BR___INTERPRETER_H
