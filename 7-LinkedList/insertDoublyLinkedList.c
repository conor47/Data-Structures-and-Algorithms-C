#include <stdio.h>
#include <stdlib.h>

struct Node  {

    struct Node *prev;
    int data;
    struct Node *next;
} *first=NULL;

void Create (int A[], int n);
void Display(struct Node *p);
int Length (struct Node *p);
void Insert (struct Node *p, int index, int x);

int main(){
    
    int A[] = {10,20,30,40,50};
    Create(A,5);
    Insert(first,0,25);
    printf("\nLength of the linked list is %d\n", Length(first));
    Display(first);
    return 0;
}

void Create (int A[], int n){

    struct Node *t, *last;
    int i;

    first = (struct Node *) malloc (sizeof(struct Node));
    first->data = A[0];
    first->prev=first->next=NULL;
    last = first;

    for (i=1; i<n; i++){

        t = (struct Node *) malloc (sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){

    while (p){

        printf("%d ", p->data);
        p = p->next; 
    }

    printf("\n");
}

int Length (struct Node *p){

    int length =0;

    while (p){

        length++;
        p=p->next;
    }

    return length;
}

void Insert (struct Node *p, int index, int x){

    struct Node *t;
    int i;

    if (index < 0 || index > Length(p)){

        return;
    }
    if(index == 0){

        t = (struct Node *) malloc (sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }

    else {

        for(i=0; i<index-1;i++){

            p=p->next;
        }

        t = (struct Node *) malloc (sizeof(struct Node));

        t->data=x;
        t->prev =p;
        t->next=p->next;
        if(p->next){
            p->next->prev = t;
        }
        p->next=t;
    }
}