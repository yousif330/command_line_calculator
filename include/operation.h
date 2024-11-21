#ifndef _OPERATION_
#define _OPERATION_

#include "stack.h"

int is_operator(char op);
int is_unary(char op);
int out_pre(char op);
int in_pre(char op);
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div_(double a, double b, Node_i *stack);

#endif