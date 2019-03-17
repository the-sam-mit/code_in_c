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

nodes insert(nodes start,int a[],int n,int ind){
    if(ind<n){
        start=newnode(a[ind]);
        start->left=insert(start->left,a,n,2*ind+1);
        start->right=insert(start->right,a,n,2*ind+2);
    }
    return start;
}

void postorder_traversal(nodes start){
    if(start!=NULL){
        postorder_traversal(start->left);
        postorder_traversal(start->right);
        printf("%d ",start->data);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    nodes start=insert(start,a,n,0);
    postorder_traversal(start);
}