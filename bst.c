#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
typedef struct node* nodes;
nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->left=NULL;
    x->right=NULL;
    return x;
}

nodes insert_BST(nodes start,int data){
    nodes x=newnode(data);
    if(start==NULL){
        start=x;
    }
    else{

        if(data < (start->data)){start->left=insert_BST(start->left, data);} 
        else if(data > (start->data)) start->right=insert_BST(start->right, data);
    }
    return start;
}

int BST(nodes start, int data){
    if(start==NULL) return 0;
    if(start->data==data){return 1;}
    if(start->data<data) return BST(start->right, data);
    if(start->data>data) return BST(start->left, data); 
}

void inorder_traversal(nodes start){
    if(start!=NULL){
        inorder_traversal(start->left);
        printf("%d ",start->data);
        inorder_traversal(start->right);
    }
}
int main(){
    int n,data;
    scanf("%d",&n);
    nodes start=NULL;
    for (int i=0;i<n;i++){
        scanf("%d",&data);
        start=insert_BST(start,data);
    }
    inorder_traversal(start);
    scanf("%d",&data);
    int flag=BST(start, data);
    if(flag==0) printf("Not Found\n");
    else printf("Found\n");
}