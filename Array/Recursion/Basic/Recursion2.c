#include <stdio.h>

// infinite exciqution

void mult(){
    printf("\nmult()");
    mult();
}

int main (){

    mult();

    return 0;
}