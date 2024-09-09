/*
int isalnum(int c)
------------------

True Conditions:
    ch is a lowercase letter (a-z)
    ch is an uppercase letter (A-Z)
    ch is a digit (0-9)

False Conditions:
    ch is a special character (!, @, #, $, etc.)
    ch is a whitespace character (space, tab, newline, etc.)
    ch is a punctuation mark (., ?, :, etc.)
    ch is a mathematical operator (+, -, *, /, etc.)
    ch is a bracket or parenthesis ([, ], (, ), etc.)
    ch is a null character (\0)
*/
#include <stdio.h>
#include <ctype.h> //use for excessing isalnum() function
#include <string.h> //use for reverse string
#define SIZE 50    // MACRO

char stack[SIZE];
int top = -1;

void push(char element) // you can write push(char element) also:-void would be added by DEFAULT
{
    stack[++top] = element;
}

char pop()
{
    return (stack[top--]);
}

int priority(char element)
{
    switch (element)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void reverse(char str[])
{
    int i, j, temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    char ch, element;
    int i = 0, k = 0;

    push('#'); // # use for Checkpost

    // Reverse the infix expression
    char temp[50];
    strcpy(temp, infix);
    reverse(temp);

    while ((ch = temp[i++]) != '\0')
    {
        if (ch == ')')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            prefix[k++] = ch;
        }
        else if (ch == '(')
        {
            while (stack[top] != ')')
            {
                prefix[k++] = pop();
            }
            element = pop(); // Used for removing ')'
        }
        else
        {
            while (priority(stack[top]) > priority(ch)) // note:- (+) >=(+) condition satisfy
            {
                prefix[k++] = pop();
            }
            push(ch);
        }
    }
    while (stack[top] != '#')
    {
        prefix[k++] = pop();
    }
    prefix[k] = '\0';

    // Reverse the prefix expression
    reverse(prefix);
}

int main()
{
    char infix[50], prefix[50];

    printf("-------------------READ THE INFIX-------------------------");
    printf("\nEnter Infix Expression : ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("\n\nGiven Infix Expression : %s  \nPrefix Expression : %s\n", infix, prefix);

    return 0;
}