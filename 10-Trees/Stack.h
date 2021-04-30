#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack {

    int size;
    int top;
    struct Node **S;
};

void StackCreate (struct Stack *st, int size){

    st->size = size;
    st->top=-1;
    st->S = (struct Node **) malloc (st->size * sizeof(struct Node *));
}

void Push(struct Stack *st, struct Node *x){

     if (st->top == st->size - 1){

         printf("Stack Overflow \n");
     }

    else {

        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *Pop(struct Stack *st){

    struct Node *x = NULL;

    if(st->top == -1){

        printf("Stack Underflow\n");
    }

    else{

        x = st->S[st->top--];
    }

    return x;
}

int isEmptyStack(struct Stack st){

    if(st.top == -1){

        return 1;
    }
    else {

        return 0;
    }
}

int isFullStack(struct Stack st){

    return st.top == st.size - 1;
}

    
