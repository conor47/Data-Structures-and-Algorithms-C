#include <stdio.h>

int expon(int m, int n);
int power (int m, int n);

int main(){

    printf("%d\n", power(2,9));
}

int expon(int m, int n){

    if (n == 0){
        
        return 1;
    }

    if ( n == 1){

        return m;
    }

    else{

        return expon(m, n - 1) * m;
    }
}

// better, more efficient version

int power (int m, int n){

    if ( n == 0){

        return 1;
    }

    else if ( n % 2 == 0){

        return power( m * m , n/2);
    }

    else {

        return m * power(m * m , (n - 1)/ 2);
    }
    
    
}