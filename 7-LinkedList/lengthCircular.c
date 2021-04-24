#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;

} *Head;


void Create (int A[], int n);
void Display (struct Node *h);
int Length(struct Node *p);


int main (){

    int A[] = {2,3,4,5,6};
    Create(A,5);
    Display(Head);
    printf("\nThe length of the linked list is %d \n", Length(Head));
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

void Display (struct Node *h){

    do {
        printf("%d ", h->data);
        h=h->next;
    } while (h != Head);

    printf("\n");
}

int Length(struct Node *p){

    int len = 0;

    do {

        len ++;
        p = p->next;
    }
    while (p != Head);
    return len;
}