#include <stdio.h>

void Swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Merge (int A[], int l, int mid, int h){

    int i=l,j=mid+1,k=l;  
    int B[100];

    while ( i <= mid && j <= h){

        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }
    for(; i <= mid; i++){
        B[k++] = A[i];
    }
    for(; j <= h; j++){
        B[k++] = A[j];
    }
    for (int i=l; i<=h; i++){
        A[i] = B[i];
    }
}

void iterativeMergeSort ( int A[], int n){

    int p,l,h,mid,i;

    for ( p=2; p<=n; p=p * 2){

        for(i=0; i+p-1<n; i=i+p){
            l=i;
            h= i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2 < n){
        Merge(A, 0, p/2-1, n-1);
    }
}

int main (){

    int A[] = { 3,7,9,10,6,9,12,4,11,2}, n=10, i;

    iterativeMergeSort(A,n);

    for (int i=0; i<n ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}