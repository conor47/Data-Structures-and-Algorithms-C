#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int LinearSearch ( struct Array arr, int key);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d \n" , LinearSearch(arr, 2));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int LinearSearch ( struct Array arr, int key){

    int i;

    for ( i=0; i<arr.length; i++){

        if (arr.A[i] == key){

            return i;
        }
    }

    return -1;    
}

