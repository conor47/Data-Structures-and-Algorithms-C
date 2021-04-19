#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
void RemoveDuplicate(struct Node *p);

int main(){

    int A[] = {3,5,5,7,10,10,10,12,15};
    Create(A, 8);
    RemoveDuplicate(first);
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

void RemoveDuplicate(struct Node *p){

    struct Node *q = p->next;

    while (q != NULL){

        if(p->data != q->data){
            
            p=q;
            q=q->next;
        }
        else 
        {

            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}