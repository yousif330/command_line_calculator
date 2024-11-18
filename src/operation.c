#include <stdlib.h>
#include <stdio.h>
#include "operation.h"
#include "stack.h"

// checking if a character is an operator and returns its precedence if true
int oper(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
    }
}

// all the basic operations

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div_(int a, int b, Node_i *stack)
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