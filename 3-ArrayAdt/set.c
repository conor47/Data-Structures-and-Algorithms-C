#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

void set (struct Array *arr , int index, int value);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    set(&arr, 2 , 47);
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

void set (struct Array *arr , int index, int value){

    if (index >= 0 && index <= arr->length){

        arr->A[index] = value;
    }

}