#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

void Insert(struct Array *arr, int index, int x);
void Display( struct Array arr);

int main(){

    struct Array arr =b {{2,4,6,8,10}, 10,5};
    
    Insert(&arr, 0, 20);
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

void Insert(struct Array *arr, int index, int x){

    int i;

    if(index >= 0 && index <= arr->length){

        for (i = arr->length ; i > index; i-- ){
            
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length ++;
    }
}