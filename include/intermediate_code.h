//
// Created by 13069 on 2024/11/6.
//

#ifndef COMPILER_INTERMEDIATE_CODE_H
#define COMPILER_INTERMEDIATE_CODE_H

#include<iostream>
#include<function.h>

//ȫ�ֱ�����ʼ����ʱ���ȴ洢������Ȼ�����main����֮��ֱ�ӽ�����ȫ�����
extern std::vector<std::string> assign_strs;

//�洢����ȫ�ֱ�����ʼ�����ַ���
extern int store_register_cnt;

class Register_Pair {
public:
    std::string Register;
    std::string Type;

    Register_Pair(std::string Register_Pair_ = "", std::string Type_ = "")
            : Register(std::move(Register_Pair_)), Type(std::move(Type_)) {}
};

//��ǰʹ�õ���ʱ�Ĵ���
extern int register_cnt;

//�Ƿ��Ѿ������˺���
extern bool is_global;

//������������������ǰ��������
void Define_Function(const std::string &FuncType, const std::string &FuncName);

//��ǰ�����ĺ�������ӱ���
void Define_Function_Params(const std::string &ParamType, const std::string &ParamName);

//�������������������Ļ���
void Define_Varible(const std::string &VarType, const std::string &VarName, int ArrayLength = 0);

//�������鸳ֵ
void
Assign_Varible_Const_NotArray(const std::string &VarName, const std::string &VarType, bool global_state, int value);

//�����鸳ֵ��һ��i**
void Assign_Varible_Ptr_Array(const Register_Pair &LeftRegister,const Register_Pair &RightRegister);

//���������ص���ʱ�Ĵ�����
Register_Pair Load_Varible(const std::string &VarName, const std::string &VarType, bool global);

//������������
Register_Pair Load_Varible_Array(const std::string &VarName, const std::string &VarType, bool global,int ArrayLength);

//������ʽ��ֵ,���ص�����ʱ������Ĵ����Լ����Ӧ������
Register_Pair Handle_Exp(Register_Pair LeftArg, Register_Pair RightArg, const std::string &ope);

//��i8���͵�תΪi32����
Register_Pair Sext_Register(const Register_Pair &Arg);

//��������'����'��ֵ
void
Assign_Varible_Not_Array(Register_Pair leftPair,
                         Register_Pair registerPair);

//�����������ʼ����ֵ
void Array_Init_Const(const std::string &VarName, const std::string &VarType, int ArrayLength, bool global,
                      const std::vector<int> &values);

//�����������ʼ����ֵ
void Array_Init_Var(const std::string &VarName, const std::string &VarType, int ArrayLength, bool global,
                    const std::vector<Register_Pair> &values);

//����ǰ����ʱ�Ĵ�����������չ
Register_Pair Zext_Register(const Register_Pair &registerPair);

//����ǰ����ʱ�Ĵ������нض�
Register_Pair Trunc_Register(const Register_Pair &registerPair);

//���ص�ǰ������Ԫ��
Register_Pair
Load_Current_Array_Element( std::string VarName, std::string VarType, bool global, int Array_Length,
                            Register_Pair registerPair);

//���ú���
Register_Pair Call_Func(const std::string &FuncName, const std::string &FuncType, std::vector<std::string> par_types,
                        std::vector<Register_Pair> par_regs);

//��ǰ�Ĳ�����ӳ����ַ���
void Add_String(const std::string &str, bool need_print = false);

//�ѱ���ת��bool����
Register_Pair To_Bool(const Register_Pair &registerPair);

//if��ǩ��ת
void
If_Jump(Register_Pair registerPair, int depth, const std::string &Then_Register, const std::string &Else_Register);

//��������
void Func_Return(const std::string &FuncType, Register_Pair registerPair);

//���ȫ�ֱ����ĸ�ֵ
void Print_Global();

//�ں���������ʱ���β�ת�Ƶ����������ı�����
void Move_FParams(const std::string &FormRegister, const std::string &NewRegister, const std::string &VarType);

//������ݣ���һ�������Ǹ�ʽ���ַ������ڶ�������������ļĴ���
void Print(const std::string &FormatString, std::vector<Register_Pair> OutPars);

//��Ŀ�����͵�Trunc
Register_Pair Trunc_Register_Bool(const Register_Pair &registerPair);

//��������ַ��ĺ���
void Call_PutChar(const std::string &CharName);

//����������ֵĺ���
void Call_PutInt(const std::string &IntName);

//��or�������жϵ�ǰ��ʱ�Ĵ����Ƿ���0
Register_Pair Judge_Zero(Register_Pair registerPair);

//��judge_var���ȫ�ֱ�����ֵ
void Load_1_Reg();

void Load_0_Reg();

int get_cur_num(const std::string &input_str);

//�ж��Ƿ���0
Register_Pair Judge_Not_Zero(Register_Pair registerPair);

//����ָ��
Register_Pair LoadPtr(const Register_Pair &registerPair);

#endif //COMPILER_INTERMEDIATE_CODE_H
