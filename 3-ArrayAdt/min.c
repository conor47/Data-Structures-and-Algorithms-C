#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int min(struct Array arr);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d\n", min(arr));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int min(struct Array arr){

    int min = arr.A[0];
    int i;

    for ( i=1; i<arr.length; i++){
        
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}