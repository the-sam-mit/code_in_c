#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue{
    int front,rear;
    int size,curr_size;
    int* st;
};
typedef struct queue* queues;
queues declare(int n){
	queues x=(queues)malloc(sizeof(struct queue));
	x->size=n;
	x->st=(int*)malloc((x->size)*sizeof(int));
	x->front=0;
	x->rear=-1;
	x->curr_size=0;
	return x;
} 
void enqueue(queues start,int data){
	queues x=start;
	if(x->curr_size==x->size) printf("queue overflow\n");
	else{
		x->rear=(x->rear+1)%x->size;
		x->st[x->rear]=data;
		x->curr_size++;
	}
}
int dequeue(queues start){
	int data;
	queues x=start;
	if(x->curr_size==0) printf("queue underflow\n");
	else{
		data=x->st[x->front];
		x->front=(x->front+1)%x->size;
		printf("%d\n",data);
		x->curr_size--;	
	}
}
int front(queues start){
	int data;
	queues x=start;
	if(x->curr_size==0) printf("queue underflow\n");
	else{
		data=x->st[x->front];
		printf("%d\n",data);	
	}
}
int main(){
	int t,n,x,data;
	scanf("%d",&t);
	while(t--){
		char s[10];
		scanf("%d%d",&n,&x);
		queues start=declare(x);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(strcmp(s,"enqueue")==0){
				scanf("%d",&data);
				enqueue(start,data);
			}
			else if(strcmp(s,"dequeue")==0){
				dequeue(start);
			}
			else
				front(start);
		}
	}
}
