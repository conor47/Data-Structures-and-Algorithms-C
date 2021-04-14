#include <stdio.h>

int sum(int n);

int main(){

    printf("%d \n", sum(10));
}

int sum(int n){

    if ( n == 0){
        return 0;
    }

    else{
        return sum(n - 1) + n;
    }
}