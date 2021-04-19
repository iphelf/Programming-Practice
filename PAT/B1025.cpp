#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=1e6;
int N,K;
int head,node[MAXN+1],nxt[MAXN+1];
struct Node{int v,p;}a[MAXN+1];

int main(void){
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&head,&N,&K);
    int from,cost,to;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&from,&cost,&to);
        node[from]=cost;
        nxt[from]=to;
    }
    int cnt=0;
    for(int i=0,it=head;~it;it=nxt[it],i++){
        a[i].v=node[it];
        a[i].p=it;
        cnt=i+1;
    }
    for(int i=K;i<=cnt;i+=K) reverse(a+i-K,a+i);
    for(int i=0;i<cnt;i++){
        printf("%05d %d ",a[i].p,a[i].v);
        if(i==cnt-1) printf("-1");
        else printf("%05d",a[i+1].p);
        putchar('\n');
    }
    return 0;
}

/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

