//
// Created by Admin on 04.10.2024.
//

#ifndef BR___ASTNODE_H
#define BR___ASTNODE_H
#include "ASTNodeType.h"

class ASTNode {
private:

public:

virtual ~ASTNode() = default;

virtual ASTNodeType getType() const = 0;

};


#endif //BR___ASTNODE_H
