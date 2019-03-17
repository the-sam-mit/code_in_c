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
    if(ind<=n){
        start=newnode(a[ind]);
        start->left=insert(start->left,a,n,2*ind);
        start->right=insert(start->right,a,n,2*ind+1);
    }
    return start;
}

void maxHeap(int a[],int ind,int n){
    int maxx=ind;
    int left=2*ind;
    int right=2*ind+1;
    if(left<=n && a[left]>a[ind]) maxx=left;
    else maxx=ind;
    if(right<=n && a[right]>a[ind]) maxx=right;
    if(maxx!=ind){
        int temp=a[ind];
        a[ind]=a[maxx];
        a[maxx]=temp;
        maxHeap(a,maxx,n);
    }
}

void preorder_traversal(nodes start){
    if(start!=NULL){
        printf("%d ",start->data);
        preorder_traversal(start->left);
        preorder_traversal(start->right);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n+5];
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n/2;i>=1;i--){
        maxHeap(a,i,n);
    }
    nodes start=insert(start,a,n,1);
    preorder_traversal(start);
}