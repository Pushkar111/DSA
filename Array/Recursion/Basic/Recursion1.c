#include <stdio.h>

void mult()
{
    mult(); // function called by its self.
}

void sub()
{
    printf("\nsub()");
    printf("\nsub2()");
}

void add()
{
    printf("\nadd()"); 
    
    sub(); // nested Function
    
    printf("\nadd2()");
}

int main()
{

    add();

    return 0;
}
// add()
// sub()
// sub2()
// add2()