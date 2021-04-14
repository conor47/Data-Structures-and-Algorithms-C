#include <stdlib.h>
#include <stdio.h>

    struct Rectangle{
        int length;
        int breadth;
    };
int main(){
    
    struct Rectangle *p;
    p = (struct Rectangle *) malloc(sizeof(struct Rectangle));
   p->breadth=10;
   p->length=15;


}



