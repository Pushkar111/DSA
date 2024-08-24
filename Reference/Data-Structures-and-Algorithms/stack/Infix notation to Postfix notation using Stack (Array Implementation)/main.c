// program for conversion from infix-notation to postfix-notation
// using Array

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int overflow();
int underflow();
void push(int);
int pop();
int isOperator(char);
int precedence(char);
void InfixToPostfix(char infix_exp[], char postfix_exp[]);

#define SIZE 100

int TOP = -1;
char stack [SIZE];



int overflow()
{
    if (TOP == SIZE)
        return 1;
    return 0;
}



int underflow()
{
    if (TOP == -1)
        return 1;
    return 0;
}


// function for push operation
void push(int ele)
{
    if (!overflow()) {
        TOP = TOP + 1;
        stack[TOP] = ele;
    }
    return;
}


// function for pop operation
int pop()
{
    int ele;
    if (!underflow()) {
        ele = stack[TOP];
        TOP -= 1;
        return ele;
    }
    return -1;
}



int isOperator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-') {
        return 1;
    }
    return 0;
}



int precedence(char symbol)
{
    if(symbol == '^') {
        return 3;
    }
    else if(symbol == '*' || symbol == '/') {
        return 2;
    }
    else if(symbol == '+' || symbol == '-') {
        return 1;
    }
    return 0;
}


// function for Infix to Postfix conversion
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp,")");
    i=0;
    j=0;
    item=infix_exp[i];
    while(item != '\0') {
        if(item == '(') {
            push(item);
        }
        else if( isdigit(item) || isalpha(item)) {
            postfix_exp[j] = item;
            j++;
        }
        else if(isOperator(item) == 1) {
            x=pop();
            while(isOperator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')') {
            x = pop();
            while(x != '(') {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;

        item = infix_exp[i];
    }
    if(TOP>0) {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    if(TOP>0) {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0';
}



// main function
int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix,postfix);
    printf("\nPostfix Expression: ");
    puts(postfix);

    return 0;
}


