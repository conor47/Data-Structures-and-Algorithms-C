#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL,*second=NULL,*third=NULL;

void Create(int A[], int n);
void Create2(int A[], int n);
void Display(struct Node *p);
void Conacat (struct Node *p, struct Node *q);

int main(){

    int A[] = {3,5,7,10,15};
    int B[] = {1,2,3,4,5};
    Create(A, 5);
    Create2(B,5);
    Display(first);
    printf("\n");
    Display(second);
    printf("\n");
    Conacat(first, second);
    Display(third);
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

void Create2(int A[], int n){

    int i;
    struct Node *t, *last;
    second = (struct Node *) malloc (sizeof(struct Node));

    second->data = A[0];
    second->next = NULL;
    last=second;

    for ( int i=1; i<n; i++){

        t=(struct Node *) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = NULL;
        last->next =t;
        last = t; 
    }
}

void Conacat (struct Node *p, struct Node *q){

    third = p;

    while(p->next != NULL){
        p=p->next;
    }

    p->next = q;
}