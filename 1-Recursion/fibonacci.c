#include <stdio.h>

int fib(int n);

int main(){

    printf("%d \n", fib(6));
}

int fib(int n){

    if ( n <= 1){
        return n;
    }
    
    else{
        
        return fib(n - 1) + fib( n - 2);
    }
}