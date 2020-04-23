#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXN=1e3;

int N,lc[MAXN],rc[MAXN],nL[MAXN+1],nR[MAXN+1],val[MAXN],in[MAXN];
bool isRoot[MAXN];

int cnt(int rt) {
    if(rt==-1) return 0;
    nL[rt]=cnt(lc[rt]);
    nR[rt]=cnt(rc[rt]);
    return 1+nL[rt]+nR[rt];
}

void fillVal(int rt,int *in) {
    val[rt]=in[nL[rt]];
    if(nL[rt]>0) fillVal(lc[rt],in);
    if(nR[rt]>0) fillVal(rc[rt],in+nL[rt]+1);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int rt=0; rt<N; rt++) {
        scanf("%d%d",&lc[rt],&rc[rt]);
        if(~lc[rt]) isRoot[lc[rt]]=false;
        if(~rc[rt]) isRoot[rc[rt]]=false;
    }
    for(int i=0; i<N; i++) scanf("%d",&in[i]);
    sort(in,in+N);
    int root=0;
    for(int i=0; i<N; i++) if(isRoot) {
            root=i;
            break;
        }
    cnt(root);
    fillVal(root,in);
    queue<int> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()) {
        int rt=q.front();
        q.pop();
        if(rt==-1) continue;
        printf("%d%c",val[rt],++cnt==N?'\n':' ');
        q.push(lc[rt]);
        q.push(rc[rt]);
    }
    return 0;
}

/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

58 25 82 11 38 67 45 73 42
*/
