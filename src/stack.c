#include <stdlib.h>
#include <stack.h>

void push(Node **head, char data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;

    new->next = *head;
    *head = new;
}

void push_i(Node_i **head, int data)
{
    Node_i *new = (Node_i *)malloc(sizeof(Node_i));
    new->data = data;

    new->next = *head;
    *head = new;
}

char pop(Node **head)
{
    if (*head)
    {
        Node *p = *head;
        *head = (*head)->next;
        char r = p->data;
        free(p);
        return r;
    }
    else
    {
        return '\0';
    }
}

int pop_i(Node_i **head)
{
    if (*head)
    {
        Node_i *p = *head;
        *head = (*head)->next;
        int r = p->data;
        free(p);
        return r;
    }
    else
    {
        return 0;
    }
}

char top(Node *head)
{
    if (head)
    {
        return head->data;
    }
    else
    {
        return '\0';
    }
}

int is_empty(Node *head)
{
    if (head)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
