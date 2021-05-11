#include <stdio.h>

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

void recursiveMergeSort ( int A[], int l, int h){

    int mid;
    if ( l < h){

        mid = (l+h) / 2;

        recursiveMergeSort(A, l , mid);
        recursiveMergeSort(A, mid+1, h);
        Merge(A,l,mid, h);
    }
}

int main (){

    int A[] = { 3,7,9,10,6,9,12,4,11,2}, n=10, i;

    recursiveMergeSort(A,0, n-1);

    for (int i=0; i<n ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}