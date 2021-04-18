#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
int Count (struct Node *p);
void Insert(struct Node *p, int index, int x);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    Display(first);
    Insert(first, 2,10);
    printf("\n");
    Display(first);
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

int Count (struct Node *p){

    int l=0;

    while(p){
        l++;
        p=p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x){

    struct Node *t;
    int i;

    if (index < 0 || index > Count(p) ){
        
        return;
    }

    t=(struct Node *) malloc(sizeof(struct Node)); 
    t->data=x;

    if ( index == 0){

        t->next=first;
        first = t;
    }

    else {

        for(i=0; i < index-1;i++){
            p=p->next;
        }

        t->next=p->next;
        p->next=t;
    }
}