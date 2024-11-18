#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "postfix.h"
#include "stack.h"
#include "operation.h"

char *infix_to_postfix(char exp[], int size)
{
    Node *stack = NULL;
    char *postfix = (char *)malloc(sizeof(char) * size);

    int i = 0;
    int j = 0;
    for (i; exp[i] != '\0'; i++)
    {
        if (exp[i] != ' ')
        {
            // handing operands
            if (isdigit(exp[i]))
            {
                if (isdigit(exp[i + 1]))
                {
                    while (isdigit(exp[i]))
                    {
                        postfix[j] = exp[i];
                        j++;
                        i++;
                    }
                    postfix[j] = ',';
                    j++;
                    i--;
                }
                else
                {
                    postfix[j] = exp[i];
                    j++;

                    postfix[j] = ',';
                    j++;
                }
            }

            // handling parentheses
            else if (exp[i] == '(' || exp[i] == ')')
            {
                if (exp[i] == '(')
                {
                    push(&stack, '(');
                }
                else
                {
                    while (top(stack) != '(')
                    {
                        postfix[j] = pop(&stack);
                        j++;

                        postfix[j] = ',';
                        j++;
                    }
                    pop(&stack);
                }
            }

            // handling operators
            else if (oper(exp[i]))
            {
                if (stack && oper(exp[i]) <= oper(top(stack)))
                {
                    while (!is_empty(stack) && top(stack) != '(')
                    {
                        postfix[j] = pop(&stack);
                        j++;

                        postfix[j] = ',';
                        j++;
                    }
                    push(&stack, exp[i]);
                }
                else
                {
                    push(&stack, exp[i]);
                }
            }
        }
    }

    // emptying the stack
    while (!is_empty(stack))
    {
        postfix[j] = pop(&stack);
        j++;

        postfix[j] = ',';
        j++;
    }
    postfix[j] = '\0';
    free(stack);

    return postfix;
}

int evaluate_postfix(char postfix[])
{
    Node_i *stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] != ',')
        {
            // handling operands
            if (isdigit(postfix[i]))
            {
                int n = 0;
                int j = 0;
                while (postfix[i] != ',')
                {
                    if (j)
                    {
                        n = n * 10;
                    }
                    n += postfix[i] - '0';
                    j++;
                    i++;
                }
                push_i(&stack, n);
            }

            // handling operators
            else if (oper(postfix[i]))
            {
                int b = pop_i(&stack);
                int a = pop_i(&stack);

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
                }
            }
        }
    }
    int r = pop_i(&stack);
    free(stack);

    return r;
}