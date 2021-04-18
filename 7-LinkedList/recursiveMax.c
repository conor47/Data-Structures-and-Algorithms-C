#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
int RMax (struct Node *p);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    Display(first);
    printf("\nThe max value is %d\n", RMax(first));
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

void Display(struct Node *p){

    while(p != NULL){

        printf("%d ", p->data);
        p=p->next;
    }
} 

int RMax (struct Node *p){

    int x=0;

    if(p == 0){
        return INT32_MIN;
    }

    x = RMax(p->next);
    if (x > p->data){
        return x; 
    }
    else
    {
        return p->data;
    }
}