#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* nodes;

struct stack{
    struct node* top;
};
typedef struct stack* stacks;

struct cnode{
    char data;
    struct cnode *next;
};
typedef struct cnode* cnodes;

struct cstack{
    struct cnode* top;
};
typedef struct cstack* cstacks;

cnodes newcnode(char data){
    cnodes x=(cnodes)malloc(sizeof(struct cnode));
    x->data=data;
    x->next=NULL;
    return x;
}

nodes newnode(int data){
    nodes x=(nodes)malloc(sizeof(struct node));
    x->data=data;
    x->next=NULL;
    return x;
}

void push(stacks st,int n){

    nodes x=newnode(n);
    if(st->top==NULL){
        st->top=x;
    }
    else{
        x->next=st->top;
        st->top=x;
    }
}

int pop(stacks st){
    if(st->top==NULL) printf("stack underflow\n");
    else{
        int x=st->top->data;
        st->top=st->top->next;
        return x;
    }
}

void cpush(cstacks st,char n){
    cnodes x=newcnode(n);
    if(st->top==NULL){
        st->top=x;
    }
    else{
        x->next=st->top;
        st->top=x;
    }
}

char cpop(cstacks st){
    if(st->top==NULL) printf("cstack underflow\n");
    else{
        char x=st->top->data;
        st->top=st->top->next;
        return x;
    }
}
void process(stacks st, cstacks cst){
    int v1=pop(st);
    char o1=cpop(cst);
    int v2=pop(st);
    printf("%d %d %c\n",v1,v2,o1);
    int ans=0;
    if(o1=='+') ans=v2+v1;
    if(o1=='-') ans=v2-v1;
    if(o1=='/') ans=v2/v1;
    if(o1=='*') ans=v2*v1;
    push(st, ans);
}

int isDigit(char c){
    if(0<=(c-'0') && (c-'0')<=9){
        return 1;
    }
    return 0;
}

int check(char ch){
    if(ch=='*' || ch=='/') return 1;
    if(ch=='+' || ch=='-') return 0;
    return -1;
}

void compute(){

}

int main(){
    int t,n,y,num=0;
    char s[1000];
    scanf("%d",&t);
    while(t--){
        stacks st=(stacks)malloc(sizeof(struct stack));
        st->top=NULL;
        cstacks cst=(cstacks)malloc(sizeof(struct cstack));
        cst->top=NULL;
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<strlen(s);i++){
            if(isDigit(s[i])==1){
                num=0;  
                while(isDigit(s[i])==1 && i<n){
                    int d=(s[i]-'0');
                    num=(num*10)+d;
                    i++;
                }
                push(st, num);
                i--;
            }
            else if((s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') && (cst->top==NULL)){
                cpush(cst, s[i]);
            }
            else if((s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') && (check(s[i])>=check(cst->top->data))){
                    cpush(cst, s[i]);   
                }
                
            else if(s[i]=='(') cpush(cst, s[i]);
            else if(s[i]==')'){
                while(cst->top->data!='(' && cst->top!=NULL){
                   process(st, cst);
                }
                cpop(cst);
            }
            else{
               
                while(cst->top!=NULL && check(cst->top->data)>=check(s[i])){
                    process(st, cst);
                }
                cpush(cst, s[i]);
            }
        }
            while(cst->top!=NULL){
                    process(st, cst);
        }
       printf("%d\n",st->top->data);
       pop(st); 
    }
}