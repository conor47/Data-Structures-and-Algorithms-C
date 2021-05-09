#include <stdio.h>

void Swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble (int A[], int n){

    int i,j,flag=0;

    for (i=0; i < n-1; i++){

        flag = 0;    

        for (j=0; j<n-1-i; j++){
            
            if(A[j] > A[j+1]){
                Swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){

    int A[] = { 3,7,9,10,6,9,12,4,11,2}, n=10, i;
    Bubble(A,10);
    
    for (int i=0; i<10 ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

