#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL,*second=NULL,*third=NULL;

void Create(int A[], int n);
void Create2(int A[], int n);
void Display(struct Node *p);
void Merge(struct Node *p, struct Node *q);


int main(){

    int A[] = {10,20,30,40,50};
    int B[] = {5,60,100,123,392};
    Create(A, 5);
    Create2(B,5);
    Display(first);
    printf("\n");
    Display(second);
    printf("\n");
    Merge(second , first);
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

void Merge(struct Node *p, struct Node *q){

    struct Node *last;

    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next = NULL;
    }
    else {
        third=last=q;
        q=q->next;
        third->next = NULL;
    }

    while(p && q){

        if(p->data < q->data){

            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }

        else{

            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p){
        last->next = p;
    }
    if(q){
        last->next = q;
    }
}