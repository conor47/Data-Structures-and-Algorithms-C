#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;

    p = (int *) malloc(5 * sizeof(int));

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i=0; i <5; i++){
        printf("%d\n", p[i]);
    }

}
  
