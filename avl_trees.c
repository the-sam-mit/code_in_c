#include<stdio.h>
#include<stdlib.h>
struct node{
    int data,height;
    struct node *left, *right;
};
typedef struct node* nodes;
nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->height=1;
    x->left=NULL;
    x->right=NULL;
    return x;
}

int height(nodes start){
	if(start==NULL) return 0;
	return start->height;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}

nodes right_rot(nodes start){
	nodes temp=start->left;
	nodes temp2=start->left->right;

	temp->right=start;
	start->left=temp2;
	
	start->height=max(height(start->left),height(start->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	return temp;
}

nodes left_rot(nodes start){
	nodes temp=start->right;
	nodes temp2=start->right->left;

	temp->left=start;
	start->right=temp2;
	
	start->height=max(height(start->left),height(start->right))+1;
	temp->height=max(height(temp->left),height(temp->right))+1;
	return temp;
}

nodes update(nodes start,int data){
	start->height=1+max(height(start->left),height(start->right));
	int bal_fact=height(start->left)-height(start->right);
	if(bal_fact>1 && data<start->left->data)
		return right_rot(start);
	else if(bal_fact<-1 && data>start->right->data)
		return left_rot(start);
	else if(bal_fact>1 && data>start->left->data){
		start->left=left_rot(start->left);
		return right_rot(start);
	}
	else if(bal_fact<-1 && data<start->right->data){
		start->right=right_rot(start->right);
		return left_rot(start);
	}
	return start;
}

nodes insert(nodes start,int data){
	nodes x=newnode(data);
	if(start==NULL) return x;
	else if(data<start->data)
		start->left=insert(start->left,data);
	else if(data>start->data)
		start->right=insert(start->right,data);
	else return start;
	nodes temp=update(start,data);
}

void preorder(nodes start){
	if(start!=NULL){
		printf("%d ",start->data);
		preorder(start->left);
		preorder(start->right);
	}
}


int main(){
	nodes start=NULL;
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		start=insert(start,data);	
	}
	preorder(start);

}
