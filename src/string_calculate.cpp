//
// Created by xht  on 2024/10/11.
//
#include"string_calculate.h"



int eval_expr(const std::vector<std::string> &expr) {
    if(expr.empty()){
        return 0;
    }
    Parser parser(expr);
    return parser.parse();
}