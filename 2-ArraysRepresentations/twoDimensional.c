#include <stdlib.h>
#include <stdio.h>

int main(){

    int **C;

    C = (int **) malloc(3 * sizeof(int *));
    C[0] = (int *) malloc (4 * sizeof(int));
    C[1] = (int *) malloc (4 * sizeof(int));
    C[2] = (int *) malloc (4 * sizeof(int));

    for ( int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            printf("%d\n", C[i][j]);
        }
    }
}

 