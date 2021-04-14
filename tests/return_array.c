#include <stdlib.h>
#include <stdio.h>

int * func(int n){
    int* p;
    p = (int *) malloc(n * sizeof(int));
    return (p);
}

int main(){
    int * A;
    A = func(5);

    for (int i = 0; i < 5; i++){
        printf("%p\n" , &A[i]);
    }
}


s