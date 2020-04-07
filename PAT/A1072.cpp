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

const int MAXN=1e3+10,MAXE=1e4*2,INF=0x3f3f3f3f;
struct Edge {
    int to,next,cost;
};

int N,M,D,nEdge,head[MAXN+2],d[MAXN+2];
Edge edge[MAXE];
bool mark[MAXN+2];

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
int getId(char s[5]) {
    if(s[0]!='G') return atoi(s);
    else return atoi(s+1)+N;
}
bool Dijkstra(int source,int &minD,int &totD) {
    memset(d,INF,sizeof d);
    memset(mark,false,sizeof mark);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    d[source]=0;
    pq.push(mp(0,source));
    while(!pq.empty()) {
        int from,to,cost;
        from=pq.top().second;
        pq.pop();
        if(mark[from]) continue;
        mark[from]=true;
        for(int i=head[from]; ~i; i=edge[i].next) {
            to=edge[i].to;
            if(mark[to]) continue;
            cost=edge[i].cost;
            if(d[to]>d[from]+cost) {
                d[to]=d[from]+cost;
                pq.push(mp(d[to],to));
            }
        }
    }
    minD=d[1];
    totD=0;
    int maxD=d[1];
    for(int i=1; i<=N; i++) {
        minD=min(minD,d[i]);
        maxD=max(maxD,d[i]);
        totD+=d[i];
    }
    if(maxD>D) return false;
    else return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int K,from,to,cost;
    char sFrom[5],sTo[5];
    while(~scanf("%d%d%d%d",&N,&M,&K,&D)) {
        init();
        for(int i=0; i<K; i++) {
            scanf(" %s %s %d",sFrom,sTo,&cost);
            from=getId(sFrom);
            to=getId(sTo);
            addEdge(from,to,cost);
            addEdge(to,from,cost);
        }
        int minD,totD;
        // minD+, totD-, n-
        vector< pair<int,pii> > v;
        for(from=N+1; from<=N+M; from++)
            if(Dijkstra(from,minD,totD))
                v.push_back(mp(-minD,mp(totD,from)));
        if(v.empty())
            puts("No Solution");
        else {
            vector< pair<int,pii> >::iterator it=min_element(v.begin(),v.end());
            double avgD=double(it->second.first)/N;
            printf("G%d\n%.1f %.1f\n",
                   it->second.second-N,
                   double(-it->first),
                   round(avgD*10)/10);
        }
    }
    return 0;
}

/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
2 1 2 10
1 G1 9
2 G1 20

G1
2.0 3.3
No Solution
*/
