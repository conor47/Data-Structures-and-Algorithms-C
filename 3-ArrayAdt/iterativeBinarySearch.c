#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int BinarySearch ( struct Array arr, int key);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d \n" , BinarySearch(arr, 7));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int BinarySearch ( struct Array arr, int key){

    int low, mid, high;
    
    low = 0;
    high = arr.length - 1;

    while ( low <= high){

        mid = (low + high) / 2;

        if ( key == arr.A[mid]){
            return mid;
        }
        else if ( key < arr.A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }
    return -1;
}