#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

void InsertSort (struct Array *arr, int x);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    InsertSort(&arr, 12);
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

void InsertSort (struct Array *arr, int x){

    int i = arr->length - 1;
    if(arr->length == arr->size){
        return ;
    }

    while(i >= 0 && arr->A[i] > x){

        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = x;
    arr->length ++;

}