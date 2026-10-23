#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int item)
{
    top++;
    stack[top] = item;
}

int pop()
{
    int item = stack[top];
    top--;
    return item;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int operand1, operand2, result;
    char ch;

    while (exp[i] != '\0')
    {
        ch = exp[i];

        if (ch == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 == 0)
                    {
                        printf("Error: Division by zero!\n");
                        return 0;
                    }
                    result = operand1 / operand2;
                    break;

                case '^':
                    result = (int)pow(operand1, operand2);
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 0;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[100];
    int result;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
