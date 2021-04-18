#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
struct Node * LSearch(struct Node *p, int key);

int main(){

    struct Node *temp;
    int A[] = {3,5,7,10,15};
    Create(A, 5);
    Display(first);
    temp=LSearch(first, 10);
    
    if( temp){
        printf("\nThe key is found %d \n", temp->data);
    }
    else 
    {
        printf("\nKey not found\n");
    }
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

struct Node * LSearch(struct Node *p, int key){

    struct Node *q;
    while (p){

        if(key == p-> data){

            q->next = p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }

    return NULL;
}