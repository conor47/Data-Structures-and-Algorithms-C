#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next; 
    
}*first=NULL;

void Create(int A[], int n);
void Display(struct Node *p);
int Count (struct Node *p);
int Delete(struct Node *p, int index);

int main(){

    int A[] = {3,5,7,10,15};
    Create(A, 5);
    printf("Deleted element is %d\n", Delete(first, 2));
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

int Delete(struct Node *p, int index){

    struct Node *q;
    int x =-1;
    int i;

    if (index < 1 || index > Count(p)){
        return -1;
    }
    if(index == 1){

        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }

    else {

        for (i=0; i<index-1; i++){

            q=p;
            p=p->next;
        }

        q->next = p->next;
        x=p->data;
        free(p);
        return x;
    }
}