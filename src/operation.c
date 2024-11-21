#include <stdlib.h>
#include <stdio.h>
#include "operation.h"
#include "stack.h"

// checking if a character is an operator
int is_operator(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case 's':
    case '!':
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}

int is_unary(char op)
{
    switch (op)
    {
    case '!':
    case 's':
        return 1;
    default:
        return 0;
    }
}

// finding operator precedence outside stack
int out_pre(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case 's':
        return 6;
    case '!':
        return 8;
    case '(':
        return 9;
    default:
        return 0;
    }
}

// finding operator precedence inside stack
int in_pre(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case 's':
        return 5;
    case '!':
        return 7;
    case '(':
        return 0;
    default:
        return 0;
    }
}

// all the basic operations

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double div_(double a, double b, Node_i *stack)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Error: dividing by zero is not allowed\n");
        free(stack);
        exit(1);
    }
}