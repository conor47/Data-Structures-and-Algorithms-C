#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void RDisplay(struct Node *p);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    RDisplay(first);
    return 0;
}

void Create(int A[], int n){

    int i;
    struct Node *t, *last;
    first = (struct Node *) malloc (sizeof(struct Node));

    first->data = A[0];
    first->next = NULL;
    last=first;

    for ( int i=1; i<n; i++){

        t=(struct Node *) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = NULL;
        last->next =t;
        last = t; 
    }
}

void RDisplay(struct Node *p){

    if(p != NULL){

        // Reverse the below statements to print in reverse order
        printf("%d ", p->data);         
        RDisplay(p->next);
    }
}