#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int Sum (struct Array arr);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d\n", Sum(arr));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int Sum (struct Array arr){

    int s=0;
    int i;

    for (i=0; i<arr.length; i++){

        s += arr.A[i];
    }

    return s;
}