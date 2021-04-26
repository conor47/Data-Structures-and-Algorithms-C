#include <stdio.h>
#include <stdlib.h>

struct Node {

    char data;
    struct Node *next;
};

struct Node *top = NULL;

char Pop ();
void Push(char x);
void Display();
int isBalanced (char *exp);


int main (){

    char *exp = "((a+b)*(c-d))";
    printf("%d \n", isBalanced(exp));
    return 0;
}

void Push(char x){

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

char Pop (){

    char x=-1;
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

int isBalanced (char *exp){

    int i;

    for (i=0; exp[i] != '\0'; i++){

        if(exp[i] == '('){
            Push(exp[i]);
        }
        else  if (exp[i] == ')'){
            if (top == NULL){
                return 0;
            }
            Pop();
    }
}
if (top == NULL){
    return 1;
}
else {
    return 0;
}
}