#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
void sortedInsert(struct Node *p, int x);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    sortedInsert(first,12);
    Display(first);
    printf("\n");

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

void sortedInsert(struct Node *p, int x){

    struct Node *t,*q=NULL;

    t=(struct Node *) malloc (sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){

        first = t;
    }
    else {

        while (p && p->data < x){

            q = p;
            p=p->next;
        }

        if (p==first){
            
            t->next=first;
            first=t;
        } 

        else {

            t->next = q->next;
            q->next = t;
        }

    }
}