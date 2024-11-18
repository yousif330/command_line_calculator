#include <stdio.h>
#include <string.h>
#include "postfix.h"

#define BUFFER_SIZE 100

int main()
{
    // safely handling an input string from the user
    char buffer[BUFFER_SIZE];

    printf("Enter mathematical expression: ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        // deleting the new-line character from the end of the string
        size_t len = strcspn(buffer, "\n");

        if (buffer[len] == '\n')
        {
            buffer[len] = '\0';
        }
    }
    else
    {
        printf("Error in receiving the input\n");
        return -1;
    }

    char *postfix = infix_to_postfix(buffer, BUFFER_SIZE);
    int result = evaluate_postfix(postfix);
    printf("%d\n", result);

    return 0;
}