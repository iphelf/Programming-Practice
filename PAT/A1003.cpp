//{Headers
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<bitset>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define mp(x,y) make_pair(x,y)
typedef long long ll;
//}

const int MAXN=5e2,MAXM=MAXN*MAXN*2,INF=0x3f3f3f3f;
struct Edge {
    int to,cost,next;
};

int N,M,S,T,nEdge,head[MAXM],dc[MAXN],w[MAXN],dw[MAXN],cnt[MAXN];
Edge edge[MAXM];
bool mark[MAXN],inq[MAXN];

void init() {
    nEdge=0;
    memset(head,-1,sizeof head);
}
void addEdge(int from,int to,int cost) {
    edge[nEdge].to=to;
    edge[nEdge].cost=cost;
    edge[nEdge].next=head[from];
    head[from]=nEdge++;
}
void Dijkstra() {
    memset(mark,false,sizeof mark);
    memset(inq,false,sizeof inq);
    memset(dc,INF,sizeof dc);
    memset(dw,INF,sizeof dw);
    memset(cnt,0,sizeof cnt);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    dc[S]=0;
    dw[S]=w[S];
    cnt[S]=1;
    pq.push(mp(0,S));
    inq[S]=true;
    while(!pq.empty()) {
        int from,to,cost,dist;
        dist=pq.top().first;
        from=pq.top().second;
        mark[S]=true;
        inq[S]=false;
        pq.pop();
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            cost=edge[i].cost;
            if(dist+cost>dc[to]) continue;
            if(dist+cost<dc[to]) {
                dc[to]=dist+cost;
                dw[to]=dw[from]+w[to];
                cnt[to]=cnt[from];
            } else {
                if(dw[from]+w[to]>dw[to])
                    dw[to]=dw[from]+w[to];
                cnt[to]+=cnt[from];
            }
            if(!inq[to]) {
                pq.push(mp(dc[to],to));
                inq[to]=true;
            }
        }
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&N,&M,&S,&T);
    init();
    int from,to,cost;
    for(int i=0; i<N; i++) scanf("%d",&w[i]);
    for(int i=0; i<M; i++) {
        scanf("%d%d%d",&from,&to,&cost);
        addEdge(from,to,cost);
        addEdge(to,from,cost);
    }
    Dijkstra();
    printf("%d %d\n",cnt[T],dw[T]);
    return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

2 4
*/
