
  #include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

void pop(char str[])
{
    strcpy(str, stack[top]);
    top--;
}

int priority(char op)
{
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    return 0;
}

// 1. Infix to Postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char op;

    top = -1;

    for(i = 0; infix[i] != '\0'; i++)
    {
        if(isspace((unsigned char)infix[i]))
            continue;

        if(isalnum((unsigned char)infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            top++;
            stack[top][0] = '(';
            stack[top][1] = '\0';
        }
        else if(infix[i] == ')')
        {
            while(top != -1 && stack[top][0] != '(')
            {
                postfix[j++] = stack[top][0];
                top--;
            }

            if(top != -1)
                top--;
        }
        else
        {
            op = infix[i];

            while(top != -1 &&
                  stack[top][0] != '(' &&
                  (priority(stack[top][0]) > priority(op) ||
                  (priority(stack[top][0]) == priority(op) && op != '^')))
            {
                postfix[j++] = stack[top][0];
                top--;
            }

            top++;
            stack[top][0] = op;
            stack[top][1] = '\0';
        }
    }

    while(top != -1)
    {
        postfix[j++] = stack[top][0];
        top--;
    }

    postfix[j] = '\0';
}

// 2. Postfix to Infix
void postfixToInfix(char postfix[], char infix[])
{
    char a[100], b[100], temp[100];
    int i;

    top = -1;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isspace((unsigned char)postfix[i]))
            continue;

        if(isalnum((unsigned char)postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            pop(b);
            pop(a);

            strcpy(temp, "(");
            strcat(temp, a);
            strncat(temp, &postfix[i], 1);
            strcat(temp, b);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(infix);
}

// 3. Prefix to Infix
void prefixToInfix(char prefix[], char infix[])
{
    char a[100], b[100], temp[100];
    int i;

    top = -1;

    for(i = strlen(prefix) - 1; i >= 0; i--)
    {
        if(isspace((unsigned char)prefix[i]))
            continue;

        if(isalnum((unsigned char)prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            pop(a);
            pop(b);

            strcpy(temp, "(");
            strcat(temp, a);
            strncat(temp, &prefix[i], 1);
            strcat(temp, b);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(infix);
}

int main()
{
    int choice;
    char expression[100];
    char result[100];

    do
    {
        printf("\n\n1. Infix to Postfix");
        printf("\n2. Postfix to Infix");
        printf("\n3. Prefix to Infix");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3)
        {
            printf("Enter expression: ");
            scanf("%99s", expression);
        }

        switch(choice)
        {
            case 1:
                infixToPostfix(expression, result);
                printf("Postfix expression = %s\n", result);
                break;

            case 2:
                postfixToInfix(expression, result);
                printf("Infix expression = %s\n", result);
                break;

            case 3:
                prefixToInfix(expression, result);
                printf("Infix expression = %s\n", result);
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
