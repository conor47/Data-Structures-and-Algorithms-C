#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

void Reverse (struct Array *arr);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    Reverse(&arr);
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

void Reverse (struct Array *arr){

    int *B;
    int i, j;

    B = (int *) malloc(arr->length * sizeof(int));

    for (i=arr->length - 1 , j=0; i>=0; i-- , j++){

        B[j] = arr->A[i];
    }
    for (i=0 ; i < arr->length; i++){

        arr->A[i] = B[i];
    }
}