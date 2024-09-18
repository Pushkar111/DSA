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
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    char ch, element;
    int i = 0, k = 0;

    push('#'); // # use for Checkpost

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            element = pop(); // Used for removing '('
        }
        else
        {
            while (priority(stack[top]) >= priority(ch)) // note:- (+) >=(+) condition satisfy
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (stack[top] != '#')
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main()
{
    char infix[50], postfix[50];

    printf("-------------------READ THE INFIX-------------------------");
    printf("\nEnter Infix Expression : ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\n\nGiven Infix Expression : %s  \nPostfix Expression : %s\n", infix, postfix);

    return 0;
}

/*
Simple Algorithm : Infix to Postfix Conversion
------------------
1) Initialize the Stack:
    • Push a special symbol # onto the stack (acts as a base marker).
    • Set up an empty postfix expression to store the result.
2) Read the Infix Expression:   
    • Process the infix expression character by character.
3) Character Handling:
    • If the character is an operand (A-Z, 0-9):
            Add it directly to the postfix expression.
    • If the character is '(' (opening parenthesis):
            Push it onto the stack.
    • If the character is ')' (closing parenthesis):
            Pop and append operators from the stack to the postfix expression until you reach the '(' Then discard the '('.
    • If the character is an operator (+, -, *, /, etc.):
            While the top of the stack has an operator with higher or equal precedence, pop it and add it to the postfix expression.
            Push the current operator onto the stack.
4) After Reading All Characters:
    • Pop all remaining operators from the stack and add them to the postfix expression.
5) End:
    • The postfix expression is now ready.
*/