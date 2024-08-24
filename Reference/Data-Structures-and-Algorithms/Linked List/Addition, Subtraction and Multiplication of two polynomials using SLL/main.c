// program for addition, subtraction and multiplication of two polynomials

#include<stdio.h>
#include<stdlib.h>


// defining structure of Node
struct Node
{
    int coeff;
    int degree;
    struct Node *next;

};

struct Node *poly1 = NULL;
struct Node *poly2 = NULL;
struct Node *poly_sum = NULL;
struct Node *poly_sub = NULL;
struct Node *poly_mul = NULL;


void display(struct Node *);
struct Node *insert_End(struct Node *, int, int);
struct Node *polyAdd(struct Node *, struct Node *, struct Node *);
struct Node *polySub(struct Node *, struct Node *, struct Node *);
struct Node *polyMul(struct Node *, struct Node *, struct Node *);


int main()
{
    int n1,n2; // size of poly-1 and poly-2
    int a, b;  // coefficient and degree of polynomials

    // for polynomial-1
    printf("\n Enter total no. of nodes in polynomial-1 : ");
    scanf("%d", &n1);
    printf("\n Enter elements(coefficient and degree) in polynomial-1 (in the order ax^2+bx^1+cx^0) :\n");
    for(int i=0; i<n1; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        poly1=insert_End(poly1, a, b);
    }
    printf("\n Polynomial-1 is : ");
    display(poly1);

    // for polynomial-2
    printf("\n\n Enter total no. of nodes in poly-2 : ");
    scanf("%d", &n2);
    printf("\n Enter elements(coefficient and degree) in poly-2 (in the order ax^2+bx^1+cx^0) :\n ");
    for(int i=0; i<n2; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        poly2 = insert_End(poly2, a, b);
    }
    printf("Polynomial-2 is : ");
    display(poly2);


    poly_sum=polyAdd(poly1, poly2, poly_sum);
    printf("\n\n Sum of the given two polynomials is : ");
    display(poly_sum);

    poly_sub=polySub(poly1, poly2, poly_sub);
    printf("\n\n Difference of the given two polynomials is : ");
    display(poly_sub);


    poly_mul=polyMul(poly1, poly2, poly_mul);
    printf("\n\n Product of the given two polynomials is : ");
    display(poly_mul);

    printf("\n");
    free(poly1);
    free(poly2);
    free(poly_sum);
    free(poly_sub);
    free(poly_mul);
    return 0;
}



// function to add two polynomials
struct Node *polyAdd(struct Node *poly1, struct Node *poly2, struct Node *poly_sum)
{
    struct Node *first = poly1, *second = poly2;
    while(first != NULL && second != NULL)
    {
        if(first->degree < second->degree)
        {
            poly_sum=insert_End(poly_sum, second->coeff, second->degree);
            second = second->next;
        }
        else if(first->degree == second->degree)
        {
            poly_sum= insert_End(poly_sum, first->coeff + second->coeff, first->degree);
            first=first->next;
            second=second->next;
        }
        else
        {
            poly_sum= insert_End(poly_sum, first->coeff, first->degree);
            first = first->next;
        }
    }

    if(first == NULL && second != NULL)
    {
        while(second != NULL)
        {
            poly_sum=insert_End(poly_sum, second->coeff, second->degree);
            second = second->next;
        }
    }
    if(second == NULL && first != NULL)
    {
        while(first != NULL)
        {
            poly_sum=insert_End(poly_sum, first->coeff, first->degree);
            first = first->next;
        }
    }
    return poly_sum;
}



// function to subtract two polynomials
struct Node *polySub(struct Node *poly1, struct Node *poly2, struct Node *poly_sub)
{
    struct Node *first = poly1, *second = poly2;
    while(first != NULL && second != NULL)
    {
        if(first->degree > second->degree)
        {
            poly_sub=insert_End(poly_sub, first->coeff, first->degree);
            first = first->next;
        }
        else if(first->degree == second->degree)
        {
            poly_sub=insert_End(poly_sub, first->coeff - second->coeff, first->degree);
            first = first->next;
            second = second->next;
        }
        else
        {
            poly_sub=insert_End(poly_sub, second->coeff, second->degree);
            second = second->next;
        }
    }

    if(first == NULL && second != NULL)
    {
        while(second != NULL)
        {
            poly_sub=insert_End(poly_sub, second->coeff, second->degree);
            second = second->next;
        }
    }
    if(second == NULL && first != NULL)
    {
        while(first!=NULL)
        {
            poly_sub=insert_End(poly_sub, first->coeff, first->degree);
            first = first->next;
        }
    }
    return poly_sub;
}



// function to multiply two polynomial
struct Node *polyMul(struct Node *poly1, struct Node *poly2, struct Node *poly_mul)
{
    struct Node *p1=poly1, *p2=poly2, *temp;
    int deg;
    temp = p2;

    while (p1 != NULL) {
        p2 = temp;
        while (p2 != NULL) {
            if (p1->degree == 0 && p2->degree == 0) {
                deg = 0;
            }
            else if (p1->degree == 0 && p2->degree != 0) {
                deg = p2->degree;
            }
            else if (p1->degree != 0 && p2->degree == 0) {
                deg = p1->degree;
            }
            else {
                deg = p1->degree + p2->degree;
            }

            poly_mul = insert_End(poly_mul, p1->coeff * p2->coeff, deg);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    struct Node *mul_res = NULL;
    int degree, coefficient;

    // adding coefficients of same degree
    while (poly_mul != NULL) {
        coefficient = 0;
        degree = poly_mul->degree;
        while (poly_mul != NULL && degree == poly_mul->degree) {
            coefficient = coefficient + poly_mul->coeff;
            poly_mul = poly_mul->next;
        }

        mul_res = insert_End(mul_res, coefficient, degree);
    }

    free(p1);
    free(p2);
    return mul_res;

}



//function to insert element at the end of linked list
struct Node *insert_End(struct Node *head, int coefficient, int degree)
{
    struct Node *newNode, *ptr;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    ptr=head;

    newNode->coeff = coefficient;
    newNode->degree = degree;
    newNode->next = NULL;

    if(ptr == NULL) {
        ptr=newNode;
        head=ptr;
    }
    else if(ptr->next == NULL) {
        ptr->next=newNode;
    }
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}



// print the elements in the list(here polynomial)
void display(struct Node *start)
{
    struct Node *head;
    head = start;
    if(start == NULL)
        printf("\n List(polynomial) is Empty!!");
    else {
        while(head->next != NULL) {
            printf("(%dx^%d) + ", head->coeff, head->degree);
            head = head->next;
        }
        printf("(%dx^%d)", head->coeff, head->degree);
    }
}




