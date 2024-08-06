#include <stdio.h>

// Base case for break recursion

void mult(int count){

    printf("\nmult()");
    if (count == 5)
    {
        return;
    }
    // count++; 
    mult(++count);
}

int main (){

    mult(1);

    return 0;
}