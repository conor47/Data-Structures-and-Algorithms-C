#include <stdio.h>

int fib (int n);
int F[10];

int main(){

    int i;

    for (i = 0; i<10; i++){
        F[i] = -1;
    }

    printf("%d \n" , fib(5));
}

int fib (int n){
    
    if ( n <= 1){

        F[n] = n;
        return n;
    }

    else{

        if (F[n - 2] == -1){
            F[n - 2] = fib(n - 2);
        }

        if (F[n - 1] == -1){
            F[n - 1] = fib(n - 1);
        }
        F[n] = F[n - 1] + F[n - 2];
        return F[n - 2] + F[n - 1];

    }

}