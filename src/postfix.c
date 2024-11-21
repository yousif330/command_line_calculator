#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "postfix.h"
#include "stack.h"
#include "operation.h"

char *infix_to_postfix(char exp[])
{
    Node *stack = NULL;
    char *postfix = (char *)malloc(sizeof(char) * (strlen(exp) + 1) * 2);

    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]) || exp[i] == '.')
        {
            postfix[j++] = exp[i++];

            if (!isdigit(exp[i]))
            {
                postfix[j++] = ',';
            }
        }
        else if (is_operator(exp[i]))
        {
            if (out_pre(exp[i]) > in_pre(top(stack)))
            {
                push(&stack, exp[i++]);
            }
            else if (out_pre(exp[i]) == in_pre(top(stack)))
            {
                pop(&stack);
                i++;
            }
            else
            {
                postfix[j++] = pop(&stack);
                postfix[j++] = ',';
            }
        }
        else
        {
            i++;
        }
    }

    // emptying the stack
    while (!is_empty(stack))
    {
        postfix[j++] = pop(&stack);
        postfix[j++] = ',';
    }
    postfix[j] = '\0';
    free(stack);

    return postfix;
}

double evaluate_postfix(char postfix[])
{
    Node_i *stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        // handling operands
        if (isdigit(postfix[i]))
        {
            int dec = 0;
            int isdouble = 0;

            double sum = 0;

            for (i; postfix[i] != ','; i++)
            {
                if (postfix[i] == '.')
                {
                    isdouble = 1;
                }
                else if (isdouble > 0)
                {
                    sum += (postfix[i] - '0') / pow(10, isdouble);
                    isdouble++;
                }
                else
                {
                    if (dec != 0)
                    {
                        sum *= 10;
                    }
                    sum += postfix[i] - '0';
                    dec = 1;
                }
            }
            push_i(&stack, sum);
        }

        // handling operators
        else if (is_operator(postfix[i]))
        {
            double b = pop_i(&stack);
            double a = 0;
            if (!is_unary(postfix[i]))
            {
                a = pop_i(&stack);
            }

            switch (postfix[i])
            {
            case '+':
                push_i(&stack, add(a, b));
                break;
            case '-':
                push_i(&stack, sub(a, b));
                break;
            case '*':
                push_i(&stack, mul(a, b));
                break;
            case '/':
                push_i(&stack, div_(a, b, stack));
                break;
            case '^':
                push_i(&stack, pow(a, b));
                break;
            case 's':
                push_i(&stack, sqrt(b));
                break;
            case '!':
                push_i(&stack, (b * -1));
                break;
            }
        }
    }
    double r = pop_i(&stack);
    free(stack);

    return r;
}