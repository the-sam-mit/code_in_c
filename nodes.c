#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char str[15];
    int data;
    struct node *next;
};
typedef struct node* nodes;

nodes newnode(int data,char ch[]){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    strcpy(x->str,ch);
    x->next=NULL;
    return x;
}

struct queue{
    struct node *front,*rear;
};
typedef struct queue* queues;


struct stack{
    struct node *top;
};
typedef struct stack* stacks;


void insert(nodes* start, nodes x){
	if(*start==NULL) *start=x;
	else if(strcmp((*start)->str,x->str)>0){
		x->next=*start;
		*start=x;
	}
	else{
		nodes t=*start,lazy=*start;
		t=t->next;
		while(t!=NULL && strcmp(t->str,x->str)<=0){
			t=t->next;
			lazy=lazy->next;
		}
		x->next=lazy->next;
		lazy->next=x;
	}
}

void enqueue(queues qu,nodes x){
	if(qu->front==NULL){
        qu->front=x;
        qu->rear=x;
    }
    else{
        qu->rear->next=x;
        qu->rear=qu->rear->next;
    }
}

nodes dequeue(queues qu){
	if(qu->front==NULL) printf("queue underflow\n"); 
	nodes x=qu->front;
    qu->front=qu->front->next;
    x->next=NULL;
    return x;
}

void push(stacks st, nodes x){
	
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
        printf("%s %d\n",st->top->str, st->top->data);
        st->top=st->top->next;
    }
}
int main(){

}