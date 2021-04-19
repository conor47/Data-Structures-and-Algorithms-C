#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
int Count(struct Node *p);
void Reverse(struct Node *p);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    Display(first);
    printf("\n\n");
    Reverse(first);
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

void Reverse(struct Node *p){

    int *A,i=0;
    struct Node *q=p;

    A=(int *) malloc(sizeof(int) * Count(p));

    while(q != NULL){

        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    
    while (q != NULL){

        q->data=A[i];
        q=q->next;
        i--;
    }

}