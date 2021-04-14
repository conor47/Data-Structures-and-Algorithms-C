    #include <stdio.h>
    #include <stdlib.h>

    struct Array  {

        int A[20];
        int size;
        int length;
    };

    struct Array* Union( struct Array *arr1, struct Array *arr2);
    void Display( struct Array arr);

    int main(){

        struct Array arr1 = {{2,6,10,15,25}, 10,5};
        struct Array arr2 = {{3,6,7,15,20}, 10,5};
        struct Array  *arr3;

        arr3 = Union(&arr1, &arr2);
        Display(*arr3 );

    }

    void Display(struct Array arr){

        int i;
        printf("Elements are : \n");

        for ( i=0; i<arr.length; i++){

            printf("%d \n", arr.A[i]);
        }
    }

    struct Array* Union( struct Array *arr1, struct Array *arr2){

        int i,j,k;
        i=j=k=0;

        struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

        while (i < arr1->length && j < arr2->length){
            
            if ( arr1->A[i] < arr2->A[j]){
                
                arr3->A[k++] = arr1->A[i++];
            }

            else if( arr2->A[j] < arr1->A[i]){

                arr3->A[k++] = arr2->A[j++];
            }

            else {
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }

        for (; i<arr1->length; i++){

            arr3->A[k++] = arr1->A[i];
        }

        for (; j<arr2->length; j++){

            arr3->A[k++] = arr2 ->A[j];
        }

        arr3->length = k;
        arr3->size = 10;

        return arr3;
    }