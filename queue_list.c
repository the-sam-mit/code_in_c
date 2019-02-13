#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* nodes;
struct queue{
    struct node *front,*rear;
};
typedef struct queue* queues;
nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->next=NULL;
    return x;
}
void enqueue(queues qu,int n){
    nodes x=newnode(n);
    if(qu->front==NULL){
        qu->front=x;
        qu->rear=x;
    }
    else{
        qu->rear->next=x;
        qu->rear=qu->rear->next;
    } 
}
void dequeue(queues qu){
    if(qu->front==NULL) printf("queue underflow\n");
    else{
        printf("%d\n",qu->front->data);
        qu->front=qu->front->next;
    }
}
void front(queues qu){
    if(qu->front==NULL) printf("queue underflow\n");
    else{
        printf("%d\n",qu->front->data);
    }
}
int main(){
    int t,n,y;
    char s[10];
    scanf("%d",&t);
    while(t--){
    	queues qu=(queues)malloc(sizeof(struct queue));
        qu->front=NULL;
        qu->rear=NULL;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            if(strcmp(s,"enqueue")==0){
                scanf("%d",&y);
                enqueue(qu,y);
            }
            else if(strcmp(s,"dequeue")==0){
                dequeue(qu);
            }
            else front(qu);
        }
    }
}