  #include <stdio.h>
#include <stdlib.h>

struct Stack {

    int size;
    int top;
    int *S;
};

void Create (struct Stack *st);
void Display (struct Stack st);
void Push(struct Stack *st, int x);
int Pop(struct Stack *st);
int peek (struct Stack st, int index);
int stackTop(struct Stack st);
int isFull (struct Stack st);
int isEmpty(struct Stack st);

int main(){

    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    printf("%d\n", peek(st,5));
    Display(st);
    return 0;
}

void Create (struct Stack *st){

    printf("Enter size : ");
    scanf("%d", &st->size);
    st->top=-1;
    st->S = (int *) malloc (st->size * sizeof(int));
}

void Display (struct Stack st){

    int i;

    for (i=st.top; i>=0; i--){

        printf("%d " , st.S[i]);
    }

    printf("\n");
}

void Push(struct Stack *st, int x){

     if (st->top == st->size - 1){

         printf("Stack Overflow \n");
     }

    else {

        st->top++;
        st->S[st->top] = x;
    }
    
}   

int Pop(struct Stack *st){

    int x=-1;

    if(st->top == -1){

        printf("Stack Underflow\n");
    }

    else{

        x = st->S[st->top--];
    }

    return x;
}

int peek (struct Stack st, int index){

    int x=-1;

    if (st.top-index+1 < 0){
        printf("Invalid index \n");
    }

    x = st.S[st.top-index+1];
    return x;
}

int isEmpty(struct Stack st){

    if(st.top == -1){

        return 1;
    }
    else {

        return 0;
    }
}

int isFull (struct Stack st){

    return st.top == st.size - 1;
}

int stackTop(struct Stack st){

    if(!(isEmpty(st))){

        return st.S[st.top];
    }

    return -1;
}