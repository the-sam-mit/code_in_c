#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define debug(x) printf("%s",x);
struct node{
    int data,wt;
    struct node *next;
};
typedef struct node* nodes;
nodes newnode(int data, int wt){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->wt=wt;
    x->next=NULL;
    return x;
}

void add_edge(nodes *start, int n, int wt){
    nodes x=newnode(n,wt);
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
void path(int x, int par[]){
    if(x==0 || x==-1) return;
    path(par[x],par);
    printf("%d ",x);
}

void compute(int par[], int v, int dis[]){
    for(int i=0;i<v;i++){
        if(dis[i]==INT_MAX) printf("NIL");
        else {printf("0 "); path(i,par);}
        printf("\n");
    }
}

void dijkstra(int v, nodes adj[]){
    int vis[v+2],par[v+2],dis[v+2];
    for(int i=0;i<v;i++){
        par[i]=0;
        dis[i]=INT_MAX;vis[i]=0;
    }
    int size=v;
    size--;
    dis[0]=0;
    par[0]=0;
    while(size>0){
    	int minn=INT_MAX,pos=0;
    	for(int i=0;i<v;i++){
    		if(minn>dis[i] && vis[i]==0){
    			minn=dis[i];
    			pos=i;
    		}
    	}
    	vis[pos]=1;
    	nodes x=adj[pos];
		while(x!=NULL){
			
      // if(vis[x->data]!=1 && (dis[x->data] == dis[pos]+(x->wt)) && par[x->data]>pos){
			// 	dis[x->data]=(dis[pos]+(x->wt));
			// 	par[x->data]=pos;
			// }  //To break the tie, lower vertex is chosen for shorter path
			
      if(vis[x->data]!=1 &&  (dis[x->data] > dis[pos]+(x->wt)) ){
				dis[x->data]=(dis[pos]+(x->wt));
				par[x->data]=pos;
			}
			x=x->next;
		}
    	size--;
    }
    compute(par, v, dis);
    
}

void make_graph(int v, int e, nodes adj[]){
    int a,b,wt;
    for(int i=0;i<v;i++){
        adj[i]=NULL;
    }
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&a,&b,&wt);
        add_edge(&adj[a], b, wt);
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
        dijkstra(v,adj);
    }
}
