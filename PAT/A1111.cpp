//{Headers
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<ctime>
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

const int MAXN=5e2,MAXE=MAXN*MAXN,INF=0x3f3f3f3f;
struct Edge {
    int to,cost,weight,next;
};

int N,S,D,nEdge,head[MAXN],dc[MAXN],dw[MAXN],dn[MAXN];
bool mark[MAXN];
Edge edge[MAXE];
int cPre[MAXN],wPre[MAXN];

void init() {
    memset(head,-1,sizeof head);
    nEdge=0;
}
void addEdge(int from,int to,int cost,int weight) {
    edge[nEdge].to=to;
    edge[nEdge].cost=cost;
    edge[nEdge].weight=weight;
    edge[nEdge].next=head[from];
    head[from]=nEdge++;
}
void cDijkstra() {
    memset(mark,false,sizeof mark);
    memset(dc,INF,sizeof dc);
    memset(dw,INF,sizeof dw);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    dc[S]=0;
    dw[S]=0;
    cPre[S]=-1;
    pq.push(mp(0,S));
    while(!pq.empty()) {
        int from,to,cost,weight;
        from=pq.top().second;
        pq.pop();
        if(mark[from]) continue;
        mark[from]=true;
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            cost=edge[i].cost;
            if(dc[to]<dc[from]+cost) continue;
            weight=edge[i].weight;
            if(mp(dc[to],dw[to])<=mp(dc[from]+cost,dw[from]+weight))
                continue;
            dc[to]=dc[from]+cost;
            dw[to]=dw[from]+cost;
            cPre[to]=from;
            pq.push(mp(dc[to],to));
        }
    }
}
void wDijkstra() {
    memset(mark,false,sizeof mark);
    memset(dw,INF,sizeof dw);
    memset(dn,INF,sizeof dn);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    dw[S]=0;
    dn[S]=1;
    wPre[S]=-1;
    pq.push(mp(0,S));
    while(!pq.empty()) {
        int from,to,weight;
        from=pq.top().second;
        pq.pop();
        if(mark[from]) continue;
        mark[from]=true;
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            weight=edge[i].weight;
            if(mp(dw[to],dn[to])<=mp(dw[from]+weight,dn[from]+1))
                continue;
            dw[to]=dw[from]+weight;
            dn[to]=dn[from]+1;
            wPre[to]=from;
            pq.push(mp(dw[to],to));
        }
    }
}
void printPath(int pre[MAXN]) {
    stack<int> s;
    for(int i=D; ~i; i=pre[i])
        s.push(i);
    while(!s.empty()) {
        printf("%d",s.top());
        s.pop();
        if(s.empty()) putchar('\n');
        else printf(" -> ");
    }
}

int main(void) {
    freopen("in.txt","r",stdin);
    int M,from,to,oneway,cost,weight;
    while(~scanf("%d%d",&N,&M)) {
        init();
        for(int i=0; i<M; i++) {
            scanf("%d%d%d%d%d",&from,&to,&oneway,&cost,&weight);
            addEdge(from,to,cost,weight);
            if(!oneway)
                addEdge(to,from,cost,weight);
        }
        scanf("%d%d",&S,&D);
        cDijkstra();
        cost=dc[D];
        wDijkstra();
        weight=dw[D];
        bool same=true;
        for(int i=D; same && ~i; i=cPre[i]) if(cPre[i]!=wPre[i]) same=false;
        if(same) {
            printf("Distance = %d; Time = %d: ",cost,weight);
            printPath(cPre);
            continue;
        }
        printf("Distance = %d: ",cost);
        printPath(cPre);
        printf("Time = %d: ",weight);
        printPath(wPre);
    }
    return 0;
}

/*
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5

Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Distance = 3; Time = 4: 3 -> 2 -> 5
*/
