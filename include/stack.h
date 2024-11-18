#ifndef _STACK_
#define _STACK_

// char stack

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

void push(Node **head, char data);
char pop(Node **head);
char top(Node *head);
int is_empty(Node *head);

// int stack

typedef struct Node_i
{
    int data;
    struct Node_i *next;
} Node_i;

void push_i(Node_i **head, int data);
int pop_i(Node_i **head);

#endif