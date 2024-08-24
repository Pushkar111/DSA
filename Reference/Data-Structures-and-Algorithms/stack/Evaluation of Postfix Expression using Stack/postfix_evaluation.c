// program to evaluate the postfix expression using stack.


#include<stdio.h>
#include<ctype.h>

#define size 100

int stack[size];
int top=-1;

void push(int);
int pop();


int main()
{
    char pe[30]; // array for storing Postfix Expression
    int i, v, op1, op2;
    printf("\n Enter any Postfix Expression : ");
    gets(pe);
    for(i=0; pe[i] != '\0'; i++) {
        if( isalpha(pe[i]) ) {
            printf("\n Enter value for %c : ", pe[i]);
            scanf("%d",&v);
            push(v);
        }
        else if( isdigit(pe[i]) ) {
            push(pe[i] - '0');
        }
        else {
            op2=pop();
            op1=pop();
            switch(pe[i]) {
                case '+' :
                    push(op1+op2);
                    break;
                case '-' :
                    push(op1-op2);
                    break;
                case '*' :
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
                case '%' :
                    push(op1%op2);
                    break;
                default:
                    printf("\n Invalid Operation");
            }
        }
    }
    printf("\n The result of Postfix Evaluation is : %d",stack[top]);
    return 0;
}



// push function
void push(int ele) {
    if(top == size-1)
        printf("\n stack overflow");
    else {
        top = top+1;
        stack[top] = ele;
    }
}



// pop function
int pop() {
    if(top == -1)
        printf("\n Stack Underflow!");
    else
        return stack[top--];
}
