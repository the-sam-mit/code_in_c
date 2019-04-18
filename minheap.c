#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
struct node{
	int size,tot;
	int arr[100005];
};
typedef struct node* nodes;

int par(int x){
	return (x-1)/2;
}
void insert(int data,nodes xx){
	if(xx->size==xx->tot){
		printf("Overflow\n");
		return;
	}
	xx->size++;
	int x=(xx->size)-1;
	xx->arr[x]=data;
	while(x!=0 && xx->arr[par(x)]>xx->arr[x]){
		int temp=xx->arr[x];
		xx->arr[par(x)]=temp;
		xx->arr[x]=xx->arr[par(x)];
		x=par(x);
	}	
}

void reduce(int ind,int data,nodes xx){
	xx->arr[ind]=data;
	while(ind!=0 && xx->arr[par(ind)]>xx->arr[ind]){
		int temp=xx->arr[ind];
		xx->arr[ind]=xx->arr[par(ind)];
		xx->arr[par(ind)]=temp;
		ind=par(ind);
	}
}

void heapify(int x,nodes xx){
	int left=(2*x)+1,right=(2*x)+2,minn=x;
	if(left<xx->size && xx->arr[left]<xx->arr[x]) minn=left;
	if(right<xx->size && xx->arr[right]<xx->arr[minn]) minn=right;
	if(minn!=x){
		int temp=xx->arr[x];
		xx->arr[x]=xx->arr[minn];
		xx->arr[minn]=temp;
		heapify(minn,xx);
	}
}

int extract(nodes xx){
	if(xx->size<=0) return INT_MAX;
	if(xx->size==1){
		xx->size--;
		return xx->arr[0];
	}
	int start=xx->arr[0];
	xx->arr[0]=xx->arr[xx->size-1];
	xx->size--;
	heapify(0,xx);
	return start;
}

void delete(int x,nodes xx){
	reduce(x,INT_MIN,xx);
	int val=extract(xx);
}

int main(){
	int n,q,data;
	scanf("%d",&n);
	nodes xx=(nodes)malloc(sizeof(struct node));
	xx->size=0,xx->tot=n;
	for(int i=0;i<2;i++){
		//for(int i=0;i<xx->size;i++) printf("%d ====\n",xx->arr[i]);
		scanf("%d%d",&q,&data);
		if(q==1) insert(data,xx);
		else delete(data,xx);
	}
	printf("%d",extract(xx));
}
