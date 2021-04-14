#include <stdio.h>

int C (int n , int r);

int main(){

    printf("%d \n" , C(100,2));
}

int C (int n , int r){

    if ( n == r || r == 0){
        return 1;
    } else {
        
        return C( n - 1, r - 1) + C (n - 1, r);
    }
}