#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

int main (){

    Treecreate();

    printf("Pre Order is : \n");
    Preorder(root);
    printf("\nPost Order is : \n");
    Postorder(root);
    printf("\nIn Order is : \n");
    Inorder(root);

    return 0;
}


