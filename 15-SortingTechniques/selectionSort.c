#include <stdio.h>

void Swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort( int A[], int n){

    int i, j ,k;

    for ( i=0; i < n-1; i++){

        for ( j=k=i; j < n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        Swap(&A[i], &A[k]);
        }
    }
}

int main(){
int A[] = {11 ,147,2,7,9,4,5, 10, 3}, n=9;
selectionSort(A, n);   
for (int i=0; i<n ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}