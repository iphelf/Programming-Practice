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

const int MAXN=5e2,MAXM=MAXN*MAXN,INF=0x3f3f3f3f;
struct Edge {
    int to,next,cost,weight;
};

int N,S,T,nEdge,head[MAXN],dc[MAXN],dw[MAXN],pre[MAXN];
bool mark[MAXN],inq[MAXN];
Edge edge[MAXM];

void init() {
    nEdge=0;
    memset(head,-1,sizeof head);
}
void addEdge(int from,int to,int cost,int weight) {
    edge[nEdge].to=to;
    edge[nEdge].cost=cost;
    edge[nEdge].weight=weight;
    edge[nEdge].next=head[from];
    head[from]=nEdge++;
}
void Dijkstra() {
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    memset(dc,INF,sizeof dc);
    memset(dw,INF,sizeof dw);
    dc[S]=dw[S]=0;
    pre[S]=-1;
    pq.push(mp(0,S));
    inq[S]=true;
    while(!pq.empty()) {
        int from,to,cost,weight;
        from=pq.top().second;
        pq.pop();
        inq[from]=false;
        mark[from]=true;
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            cost=edge[i].cost;
            weight=edge[i].weight;
            if(mp(dc[to],dw[to])>mp(dc[from]+cost,dw[from]+weight)) {
                dc[to]=dc[from]+cost;
                dw[to]=dw[from]+weight;
                pre[to]=from;
                if(!inq[to]) {
                    pq.push(mp(dc[to],to));
                    inq[to]=true;
                }
            }
        }
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,from,to,cost,weight;
    scanf("%d%d%d%d",&N,&M,&S,&T);
    init();
    for(int i=0; i<M; i++) {
        scanf("%d%d%d%d",&from,&to,&cost,&weight);
        addEdge(from,to,cost,weight);
        addEdge(to,from,cost,weight);
    }
    Dijkstra();
    stack<int> path;
    for(int i=T; ~i; i=pre[i])
        path.push(i);
    while(!path.empty()) {
        printf("%d ",path.top());
        path.pop();
    }
    printf("%d %d\n",dc[T],dw[T]);
    return 0;
}

/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

0 2 3 3 40
*/
