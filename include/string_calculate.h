//
// Created by xht  on 2024/10/11.
//

#ifndef COMPILER_STRING_CALCULATE_H
#define COMPILER_STRING_CALCULATE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include<vector>

int eval_expr(const std::string &expr);

class Parser {
private:
    std::vector<std::string> expr_;
    int index = 0;

    int PrimaryExp(){
        int a;
        if(expr_[index]=="("){
            index++;
            a=AddExp();
            if(expr_[index]==")"){
                index++;
            }
        }
        else{
            a=std::stoi(expr_[index]);
            index++;
        }
        return a;
    }

    int UnaryExp() {
        int a;
        if(expr_[index]=="+"||expr_[index]=="-"){
            if(expr_[index]=="+"){
                index++;
                a=UnaryExp();
            }
            else{
                index++;
                a=-UnaryExp();
            }
        }
        else{
            a=PrimaryExp();
        }
        return a;
    }

    int MulExp() {
        int a = UnaryExp();
        while (expr_[index] == "*" || expr_[index] == "/" || expr_[index] == "%") {
            if (expr_[index] == "*") {
                index++;
                a = a * UnaryExp();
            } else if (expr_[index] == "/") {
                index++;
                a = a / UnaryExp();
            } else {
                index++;
                a = a % UnaryExp();
            }
        }
        return a;
    }

    int AddExp() {
        int a = MulExp();
        while (expr_[index] == "+" || expr_[index] == "-") {
            if (expr_[index] == "+") {
                index++;
                a = a + MulExp();
            } else {
                index++;
                a = a - MulExp();
            }
        }
        return a;
    }


public:
    Parser(const std::vector<std::string> &expr) : expr_(expr) {}

    int parse() {
        return AddExp();
    }
};

// 外部接口
int eval_expr(const std::vector<std::string> &expr);

#endif //COMPILER_STRING_CALCULATE_H
