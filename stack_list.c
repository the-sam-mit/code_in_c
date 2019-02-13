#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* nodes;
struct stack{
    struct node* top;
};
typedef struct stack* stacks;
nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->next=NULL;
    return x;
}
void push(stacks st,int n){

    nodes x=newnode(n);
    if(st->top==NULL){
        st->top=x;
    }
    else{
        x->next=st->top;
        st->top=x;
    }
}
void pop(stacks st){
    if(st->top==NULL) printf("stack underflow\n");
    else{
        printf("%d\n",st->top->data);
        st->top=st->top->next;
    }
}
void top(stacks st){
    if(st->top==NULL) printf("stack underflow\n");
    else{
        printf("%d\n",st->top->data);
    }
}
int main(){
    int t,n,y;
    char s[10];
    scanf("%d",&t);
    while(t--){
    	stacks st=(stacks)malloc(sizeof(struct stack));
        st->top=NULL;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            if(strcmp(s,"push")==0){
                scanf("%d",&y);
                push(st,y);
            }
            else if(strcmp(s,"pop")==0){
                pop(st);
            }
            else top(st);
        }
    }
}