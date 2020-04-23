#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e4;

int N,fa[MAXN+1];
bool vis[MAXN+1];

int root(int x) {
    return x==fa[x]?x:fa[x]=root(fa[x]);
}

bool unite(int x,int y) {
    int rx=root(x),ry=root(y);
    if(rx==ry) return false;
    if(rx>ry) swap(rx,ry);
    fa[ry]=rx;
    return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<=MAXN; i++) fa[i]=i;
    memset(vis,false,sizeof vis);
    int K,bl,br;
    for(int i=0; i<N; i++) {
        scanf("%d",&K);
        if(K==0) continue;
        scanf("%d",&bl);
        vis[bl]=true;
        for(int j=1; j<K; j++) {
            scanf("%d",&br);
            vis[br]=true;
            unite(bl,br);
        }
    }
    int cntB=0,cntT=0;
    for(int i=0; i<=MAXN; i++) if(vis[i]) {
            cntB++;
            if(fa[i]==i) cntT++;
        }
    printf("%d %d\n",cntT,cntB);
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        scanf("%d%d",&bl,&br);
        if(vis[bl] && vis[br] && root(bl)==root(br)) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

2 10
Yes
No
*/
