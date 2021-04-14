#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    int length;
    int breadth;
};

struct Rectangle *fun(){
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->breadth = 20;
    p->length = 30;
    return p;
}

int main(){
    
    struct Rectangle *n;
    n = fun();

    printf("Length : %d \nBreadth : %d \n", n->length, n->breadth);

}