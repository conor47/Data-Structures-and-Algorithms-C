#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Node *root=NULL;

void Treecreate(){

    struct Node *p, *t;
    int x;
    struct Queue q;
    Create(&q, 100);
    
    printf("Enter root value");
    scanf("%d", &x);

    root=(struct Node *) malloc (sizeof(struct Node));
    root->data=x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root);

    while (!isEmpty(q)){

        p = Dequeue(&q);
        printf("Enter left child of %d ",  p->data);
        scanf("%d", &x);
        if(x != -1){

            t=(struct Node *) malloc (sizeof(struct Node));
            t->data=x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }

        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1){

            t=(struct Node *) malloc (sizeof(struct Node));
            t->data=x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }

}

void Preorder(struct Node *p){
    
    if(p){
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }

}

void Inorder(struct Node *p){
    
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }

}

void Postorder(struct Node *p){
    
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }

}

void IPreorder(struct Node *p){

    struct Stack stk;
    StackCreate(&stk,100);

    while (p || !isEmptyStack(stk)){

        if(p){
            printf("%d ", p->data);
            Push(&stk, p);
            p=p->lchild;
        }
        else{
            p=Pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(struct Node *p){

    struct Stack stk;
    StackCreate(&stk,100);

    while (p || !isEmptyStack(stk)){

        if(p){

            Push(&stk, p);
            p=p->lchild;
        }
        else{
            p=Pop(&stk);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

void LevelOrder (struct Node *root){

    struct Queue q;
    Create(&q,100);

    printf("%d ", root->data);
    Enqueue(&q, root);

    while ( ! isEmpty(q)){

        root=Dequeue(&q);
        
        if(root->lchild){
            printf("%d ", root->lchild->data);
            Enqueue(&q, root->lchild);
        }

        if(root->rchild){
            printf("%d ", root->rchild->data);
            Enqueue(&q, root->rchild);
        }
    }
}

int Count (struct Node *root){

    if(root != NULL){

        return(Count(root->lchild)+ Count(root->rchild) + 1);
    }
    return 0;
}

int Height(struct Node *root){

    int x=0,y=0;
    if (root == 0){
        return 0;
    }
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x > y){
        return x+1;
    }
    else{
        return y+1;
    }
}


int main (){

    Treecreate();

    printf("Count %d \n", Count(root));
    printf("Height %d \n", Height(root));
    return 0;
}



