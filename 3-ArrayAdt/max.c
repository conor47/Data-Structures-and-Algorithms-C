#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int max(struct Array arr);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d\n", max(arr));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int max(struct Array arr){

    int max = arr.A[0];
    int i;

    for ( i=1; i<arr.length; i++){
        
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}