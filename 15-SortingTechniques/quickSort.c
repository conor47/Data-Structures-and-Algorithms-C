#include <stdio.h>

void Swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int A[], int l, int h){

    int pivot = A[l];
    int i=l, j=h;

    do {
        do{
            i ++;
        } while ( A[i] <= pivot);

        do { 
            j--;
        } while (A[j] > pivot);

        if ( i < j ){
            Swap(&A[i], &A[j]);
        } 

    }   while ( i < j);

    Swap (&A[l], &A[j]);
    return j;
}

void QuickSort ( int A[], int l, int h){
    int j;

    if ( l < h){

        j = partition(A, l , h);
        QuickSort(A, l , j-1);
        QuickSort(A, j+1, h );
    }
}

int main (){

    int A[] = { 3,7,9,10,6,9,12,4,11,2,__INT32_MAX__}, n=11, i;

    QuickSort(A, 0 , 10);

    for (int i=0; i<10 ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}