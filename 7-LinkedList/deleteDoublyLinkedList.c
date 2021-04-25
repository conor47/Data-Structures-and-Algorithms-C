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
int Delete(struct Node *p, int index);

int main(){
    
    int A[] = {10,20,30,40,50};
    Create(A,5);
    Delete(first, 3);
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

int Delete(struct Node *p, int index){

    struct Node *q;
    int x = -1;
    int i;

    if ( index < 1 || index > Length(first)){

        return -1;
    }

    if (index == 1){

        first = first->next;
        if(first){
            first->prev = NULL;
        }

        x = p->data;
        free(p);
    }

    else {

        for ( i=0; i<index-1; i++){

            p=p->next;
        }

        p->prev->next = p->next;
        if(p->next){

            p->next->prev = p->prev;
        }

        x = p->data;
        free(p);
    }

    return x;
}
