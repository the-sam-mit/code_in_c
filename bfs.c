#include<stdio.h>
#include<stdlib.h>
#define debug(x) printf("%s",x);
struct node{
    int data;
    struct node *next;
};
typedef struct node* nodes;

nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->next=NULL;
    return x;
}

struct queue{
    struct node *front,*rear;
};
typedef struct queue* queues;

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
        qu->front=qu->front->next;
    }
}
int front(queues qu){
    if(qu->front==NULL) printf("queue underflow\n");
    else{
        return qu->front->data;
    }
}

void add_edge(nodes *start,int n){
    nodes x=newnode(n);
    if(*start==NULL){
        *start=x;
    }
    else{
        nodes t=*start;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=x;
    }
}

void compute(int dist[],int v){
    for(int i=0;i<v;i++) printf("%d\n",dist[i]);
}

void bfs(int v,nodes adj[]){
    int dist[v+2],vis[v+2];
    for(int i=0;i<v;i++){
        dist[i]=-1;
        vis[i]=0;
    }
    queues qu=(queues)malloc(sizeof(struct queue));
    qu->front=NULL;
    qu->rear=NULL;
    vis[0]=1;
    dist[0]=0;
    enqueue(qu,0);
    while(qu->front!=NULL){
        int y=front(qu);
        nodes temp=adj[y];
        dequeue(qu);
        while(temp!=NULL){
            if(vis[temp->data]==0){
                vis[temp->data]=1;
                dist[temp->data]=dist[y]+1;
                enqueue(qu,temp->data);
            }
            temp=temp->next;
        }
    }
    compute(dist,v);
}

void make_graph(int v,int e,nodes adj[]){
    int a,b;
    for(int i=0;i<v;i++){
        adj[i]=NULL;
    }
    for(int i=0;i<e;i++){
        scanf("%d%d",&a,&b);
        add_edge(&adj[a], b);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int v,e;
        scanf("%d%d", &v, &e);
        nodes adj[v];
        make_graph(v,e,adj);
        bfs(v,adj);
    }
}
