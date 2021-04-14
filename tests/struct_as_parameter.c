#include <stdio.h>

struct Test{
    int a[5];
    int n;
};

void fun(struct Test p);

int main(){
    struct Test r1={{2,4,6,8,10}, 5};
    fun(r1);
}

void fun(struct Test p){
    for (int i =0; i<p.n; i++){
        printf("%d \n", p.a[i]);
    }
}

