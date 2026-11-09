#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%49s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        if(isalnum((unsigned char)infix[i]))
            postfix[j++] = infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if(top != -1)
                pop();
        }
        else
        {
            while(top != -1 && stack[top] != '(' &&
                  (priority(stack[top]) > priority(infix[i]) ||
                  (priority(stack[top]) == priority(infix[i]) &&
                   infix[i] != '^')))
                postfix[j++] = pop();

            push(infix[i]);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
