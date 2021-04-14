#include <stdio.h>
#include <stdlib.h>

struct Array  {

    int A[20];
    int size;
    int length;
};

int rBinarySearch( struct Array arr, int low , int high, int key);
void Display( struct Array arr);

int main(){

    struct Array arr = {{2,4,6,8,10}, 10,5};
    
    printf("%d \n", rBinarySearch(arr, 0, arr.length, 8));
    Display(arr);

}

void Display(struct Array arr){

    int i;
    printf("Elements are : \n");

    for ( i=0; i<arr.length; i++){

        printf("%d \n", arr.A[i]);
    }
}

int rBinarySearch( struct Array arr, int low , int high, int key){

    int mid;

    if ( low <= high){

        mid = (low + high) / 2;

        if (key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            return rBinarySearch(arr, low, mid - 1, key);
        }
        else {
            return rBinarySearch(arr, mid+1, high, key);

        }
    }
    return -1;
}