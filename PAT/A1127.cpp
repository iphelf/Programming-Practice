#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

const int MAXN=30,MAXV=1e3;
typedef pair<int,int> pii;
#define mp(x,y) make_pair((x),(y))

int N,maxD,lc[MAXV],rc[MAXV],in[MAXN],*pIn[MAXV],post[MAXN],*pPost[MAXV];
vector<int> level[MAXN];

void dfs(int n,int *in,int *post) {
    int rt=post[n-1];
    int *pRt=pIn[rt];
    int nL=pRt-in,nR=in+n-1-pRt;
    if(nL>0) {
        dfs(nL,in,post);
        lc[rt]=post[nL-1];
    }
    if(nR>0) {
        dfs(nR,pRt+1,post+nL);
        rc[rt]=post[n-2];
    }
}

void bfs(int rt) {
    queue<pii> q;
    q.push(mp(0,rt));
    int d;
    while(!q.empty()) {
        d=q.front().first;
        rt=q.front().second;
        q.pop();
        if(rt==-1) continue;
        maxD=max(maxD,d);
        level[d].push_back(rt);
        q.push(mp(d+1,lc[rt]));
        q.push(mp(d+1,rc[rt]));
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&in[i]);
        pIn[in[i]]=&in[i];
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&post[i]);
        pPost[post[i]]=&post[i];
    }
    memset(lc,-1,sizeof lc);
    memset(rc,-1,sizeof rc);
    dfs(N,in,post);
    maxD=0;
    bfs(post[N-1]);
    for(int d=0; d<=maxD; d++) {
        if(d%2==0) reverse(level[d].begin(),level[d].end());
        for(int i=0; i<level[d].size(); i++)
            printf("%d%c",level[d][i],(d==maxD&&i==level[d].size()-1?'\n':' '));
    }
    return 0;
}

/*
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1

1 11 5 8 17 12 20 15
*/
