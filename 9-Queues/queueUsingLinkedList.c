#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;

}*front=NULL, *rear=NULL;

void Enqueue(int x);
int Dequeue ();
void Display(struct Node *t);

int main(){

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Display(front);
    Dequeue();
    Dequeue();
    Display(front);
    return 0;
}

void Enqueue(int x){

    struct Node *t;
    t = (struct Node*) malloc(sizeof(struct Node));

    if(t == NULL){

        printf("Queue is full");
    }
    else {

        t->data = x;
        t->next=NULL;
        if(front == NULL){
            front=rear=t;
        }
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue (){

    int x=-1;
    struct Node *t;

    if(front == NULL){
        printf("Queue is empty\n");
    }
    else {

        x = front->data;
        t = front;
        front=front->next;
        free(t);
    }
    return x;
}

void Display (struct Node *t){


    while(t){

        printf("%d ", t->data);
        t=t->next;
    }  
    printf("\n");

}
