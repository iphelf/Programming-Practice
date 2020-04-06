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
    int to,next,cost;
};

int N,T,C,head[MAXN+1],nEdge,bike[MAXN+1],d[MAXN+1],ansIn,ansOut;
set<int> pre[MAXN+1];
Edge edge[MAXM];
bool mark[MAXN+1],inq[MAXN+1];
stack<int> path;
stack<int> ansPath;

void init() {
    nEdge=0;
    memset(head,-1,sizeof head);
    ansIn=INF;
    ansOut=INF;
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
    memset(d,INF,sizeof d);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    d[0]=0;
    pq.push(mp(0,0));
    inq[0]=true;
    while(!pq.empty()) {
        int from,to,cost;
        from=pq.top().second;
        pq.pop();
        inq[from]=false;
        mark[from]=true;
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            cost=edge[i].cost;
            if(d[to]>d[from]+cost) {
                d[to]=d[from]+cost;
                pre[to].clear();
                pre[to].insert(from);
                if(!inq[to]) {
                    pq.push(mp(d[to],to));
                    inq[to]=true;
                }
            } else if(d[to]==d[from]+cost)
                pre[to].insert(from);
        }
    }
}
void DFS(int curr,int in,int out) {
    path.push(curr);
    if(curr==0) {
        if(mp(ansOut,ansIn)>mp(out,in)) {
            ansOut=out;
            ansIn=in;
            ansPath=path;
        }
    } else {
        int currIn=max(bike[curr]-C,0);
        int currOut=max(C-bike[curr],0);
        if(currIn>0) {
            in+=max(currIn-out,0);
            out=max(out-currIn,0);
        } else if(currOut>0) {
            out+=currOut;
        }
        for(const int &next:pre[curr])
            DFS(next,in,out);
    }
    path.pop();
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,from,to,cost;
    scanf("%d%d%d%d",&C,&N,&T,&M);
    init();
    C/=2;
    bike[0]=C;
    for(int i=1; i<=N; i++) scanf("%d",&bike[i]);
    for(int i=0; i<M; i++) {
        scanf("%d%d%d",&from,&to,&cost);
        addEdge(from,to,cost);
        addEdge(to,from,cost);
    }
    Dijkstra();
    DFS(T,0,0);
    printf("%d %d",ansOut,ansPath.top());
    ansPath.pop();
    while(!ansPath.empty()) {
        printf("->%d",ansPath.top());
        ansPath.pop();
    }
    printf(" %d\n",ansIn);
    return 0;
}

/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

3 0->2->3 0
*/
