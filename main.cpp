#include <iostream>
#include "Lekser.h"
#include "Parser.h"
#include "Interpreter.h"
int main() {
    std::string code = "x = 0; while )x < 10( { x = x + 1; } if )x == 10( { y = 20; }";
    Lekser lekser;
    // Получаем токены с помощью лексера
    auto tokens = lekser.lexer(code);

    Parser parser(tokens);

    auto ast = parser.parseProgram();
    Interpreter interpreter;
    for (const auto& node : ast) {

        interpreter.interpreter(node);
    }
    std::cout << "y = " << interpreter.variables["y"] <<std::endl;

    return 0;
}
