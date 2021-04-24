#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;

} *Head;


void Create (int A[], int n);
void RDisplay (struct Node *h);

int main (){

    int A[] = {2,3,4,5,6};
    Create(A,5);
    RDisplay(Head);
    return 0;
}

void Create (int A[], int n){

    int i;
    struct Node *t,*last;
    Head = (struct Node *) malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last = Head;

    for (i=1; i<n ; i++){

        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last ->next;
        last->next = t;
        last = t; 
    }
}

void RDisplay (struct Node *h){

    static int flag = 0;

    if ( h != Head || flag == 0){
        
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }

    flag = 0;
}