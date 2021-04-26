#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;
};

int Pop ();
void Push(int x);
void Display();

struct Node *top = NULL;

int main (){

    Push(10);
    Push(20);
    Push(30);
    Display();

    printf("%d \n", Pop());

    Display();
    return 0;
}

void Push(int x){

    struct Node *t;
    t = (struct Node *) malloc ( sizeof(struct Node));

    if(t == NULL){
        printf("stack is full \n");
    }
    else {

        t->data = x;
        t->next=top;
        top=t;
    }
}

int Pop (){

    int x=-1;
    struct Node *t;

    if (top == NULL){
        printf("Stack is empty \n");
    }
    else {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }

    return x;
}

void Display(){

    struct Node *p;
    p=top;

    while (p != NULL){

        printf("%d ", p->data);
        p=p->next;
    }

    printf("\n");
}