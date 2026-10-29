#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int isValid(char s[])
{
    int i;
    char ch;

    for (i = 0; s[i] != '\0'; i++)
    {
        ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else
        {
            if (top == -1)
                return 0;

            char open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{'))
            {
                return 0;
            }
        }
    }

    return (top == -1);
}

int main()
{
    char s[MAX];

    printf("Enter the bracket string: ");
    scanf("%s", s);

    top = -1;

    if (isValid(s))
        printf("Output: True\n");
    else
        printf("Output: False\n");

    return 0;
}
