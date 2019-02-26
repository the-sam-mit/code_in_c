#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    int* st;
};
typedef struct stack* stacks;
stacks declare(int n){
	stacks x=(stacks)malloc(sizeof(struct stack));
	x->size=n;
	x->st=(int*)malloc((x->size)*sizeof(int));
	x->top=-1;
	return x;
} 
void push(stacks start,int data){
	stacks x=start;
	if(x->top==x->size-1) printf("stack overflow\n");
	else{
		x->top=x->top+1;
		x->st[x->top]=data;
	}
}
int pop(stacks start){
	int data;
	stacks x=start;
	if(x->top==-1) printf("stack underflow\n");
	else{
		data=x->st[x->top];
		x->top=x->top-1;
		printf("%d\n",data);	
	}
}
int top(stacks start){
	stacks x=start;
	int data;
	if(x->top==-1) printf("stack underflow\n");
	else{
		data=x->st[x->top];
		printf("%d\n",data);	
	}
}
int main(){
	int t,n,x,data;
	scanf("%d",&t);
	while(t--){
		char s[10];
		scanf("%d%d",&n,&x);
		stacks start=declare(x);
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(strcmp(s,"push")==0){
				scanf("%d",&data);
				push(start,data);
			}
			else if(strcmp(s,"pop")==0){
				pop(start);
			}
			else
				top(start);
		}
	}
}