cmake_minimum_required(VERSION 3.25)
project(BR__)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
add_executable(BR__ main.cpp Lekser.cpp Lekser.h ASTnodes/ASTNode.h ASTnodes/ASTNodeType.h ASTnodes/NumberNode.h ASTnodes/VariableNode.h ASTnodes/BinaryOpNode.h ASTnodes/AssigmentNode.h Parser.cpp Parser.h Token.h TokenType.h ASTnodes/IfElseNode.h ASTnodes/WhileNode.h Interpreter.cpp Interpreter.h)
