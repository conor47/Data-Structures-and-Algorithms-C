#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

    int data;
    struct Node *next;
};

struct Node *top = NULL;

int Pop ();
void Push(int x);
void Display();
int isBalanced (char *exp);
int Pre(char x);
int isOperand (char x);
char * InToPost (char *infix);
int Evaluate(char * postfix);

int main (){

    char *postfix = "234*+82/-";

    printf("Result is %d\n", Evaluate(postfix));

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

int Pre(char x){

    if (x=='+' || x=='-'){
        return 1;
    }
    else if (x =='*' || x =='/'){
        return 2;
    }
    return 0;
}

int isOperand (char x){

    if ( x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

char * InToPost (char *infix){

    int i=0, j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *) malloc ((len+2) * sizeof(char));

    while (infix[i] != '\0'){

        if (isOperand(infix[i])){
            postfix[j++] = infix [i++];
        }

        else {

            if(Pre(infix[i]) > Pre(top->data)){
                Push(infix[i++]);
            }
            else {
                postfix[j++] = Pop();
            }
        }
    }

    while (top != NULL){
        postfix[j++] = Pop();
    }
    postfix[j] ='\0';
    return postfix;
}

int Evaluate(char * postfix){

    int i=0;
    int x1,x2,r;

    for (i=0;postfix[i] != '\0'; i++){

        if(isOperand(postfix[i])){
            Push(postfix[i] - '0');
        }
        else{

            x2 = Pop();
            x1 = Pop();

            switch(postfix[i]){

                case '+' : r=x1+x2;
                break;

                case '-' : r=x1-x2;
                break;

                case '*' : r=x1*x2;
                break;

                case '/' : r=x1/x2;
                break;

            }
            Push(r);
        }
    }

    return top->data;
}
