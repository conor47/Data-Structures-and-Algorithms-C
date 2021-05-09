#include <stdio.h>

void InsertionSort (int A[], int n){

    int i,j,x;

    for(i=1; i<n; i++){

        j=i-1;
        x=A[i];

        while(j > -1 && A[j] > x){

            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main (){

    int A[] = { 3,7,9,10,6,9,12,4,32,1,8,2}, n=12, i;
    InsertionSort(A,n);

    for (int i=0; i<n ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}