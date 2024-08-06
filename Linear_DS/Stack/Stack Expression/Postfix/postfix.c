/*

Input :==>     4 6 + 2 / 5 * 7 +

Output :==>    10 2 / 5 * 7 +
               5 5 * 7 +
               25 7 +
               32

1) push 4 in stack
2) push 6 in stack
3) For Addition pop 4 and 6 from stack and perform addition so we get 4 + 6 = 10
4) push Ans 10 in stack
5) push 2 in stack
6) For Division pop 10 and 2 from stack and perform division so we get 10 / 2 = 5
7) push Ans 5 in stack
8) push 5 in stack
9) For Multiplication pop 5 and 5 from stack and perform multiplication so we get 5 * 5 = 25
10) push Ans 25 in stack
11) push 7 in stack
12) For Addition pop 25 and 7 from stack and perform addition so we get 25 + 7 = 32

*/

/*

Input :==>        7 8 + 3 2 + /

Output :==>       15 3 2 + /
                  15 5 /
                  3

*/


#include <stdio.h>
#include <string.h>
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

int postfixEvaluation(int stack[], int *top, char str[])
{

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            push(stack, top, str[i] - '0'); // return as a int value { str[i] - '0' }
        }
        else
        {

            int b = pop(stack, top);
            int a = pop(stack, top);
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
    return pop(stack, top);
}

int main()
{
    int stack[SIZE];
    int *top; 
    *top = -1;

    char str[SIZE] = "46+2/5*7+";
    // char str[SIZE] = "78+32+/";

    int ans = postfixEvaluation(stack, top, str);

    printf("\nAnswer = %d\n", ans);

    return 0;
}