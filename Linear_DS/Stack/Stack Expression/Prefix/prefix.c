/*

Input :==>     - + 7 * 4 5 + 2 0

Output :==>    - + 7 * 4 5 2 
               - + 7 20 2
               -  27 2
               25

1) push 2 in stack
2) push 0 in stack
3) For Addition pop 2 and 0 from stack and perform addition so we get 2 + 0 = 2
4) push Ans 2 in stack
5) push 5 in stack
6) push 4 in stack
7) For Multiplication pop 5 and 4 from stack and perform multiplication so we get 5 * 4 = 20
8) push Ans 20 in stack
9) push 7 in stack
10) For Addition pop 7 and 20 from stack and perform addition so we get 7 + 20 = 27
11) push Ans 27 in stack
12) For Subtraction pop 27 and 2 from stack and perform subtraction so we get 27 - 2 = 25

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 100

void push(int stack[], int *top, int no)
{
    (*top)++;
    stack[*top] = no;
}

int pop(int stack[], int *top)
{
    int val = stack[*top];
    (*top)--;
    return val;
}

int prefixEvaluation(int stack[], int *top, char str[])
{
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        // Check if the character is an operand
        if (str[i] >= '0' && str[i] <= '9')
        {
            push(stack, top, str[i] - '0');
        }
        else
        {
            int a = pop(stack, top);
            int b = pop(stack, top);
            switch (str[i])
            {
            case '+':
                push(stack, top, a + b);
                break;
            case '-':
                push(stack, top, a - b);
                break;
            case '*':
                push(stack, top, a * b);
                break;
            case '/':
                push(stack, top, a / b);
                break;
            case '%':
                push(stack, top, a % b);
                break;
            }
        }
    }
    return pop(stack, top); // Return the final result
}

int main()
{
    int stack[SIZE];
    int top = -1; // Initialize top as an integer

    char str[SIZE] = "-+7*45+20";

    int ans = prefixEvaluation(stack, &top, str);
    printf("\nAnswer = %d\n", ans);

    return 0;
}
