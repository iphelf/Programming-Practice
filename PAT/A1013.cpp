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

const int MAXN=1e3,MAXE=MAXN*MAXN;
struct Edge {
    int to,next;
};

int N,head[MAXN],nEdge;
Edge edge[MAXE];
vector<bool> mark(MAXN);

void init() {
    nEdge=0;
    memset(head,-1,sizeof head);
}
void addEdge(int from,int to) {
    edge[nEdge].to=to;
    edge[nEdge].next=head[from];
    head[from]=nEdge++;
}
void DFS(int from) {
    mark[from]=true;
    int to;
    for(int iEdge=head[from]; ~iEdge; iEdge=edge[iEdge].next) {
        to=edge[iEdge].to;
        if(!mark[to]) DFS(to);
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,K,from,to;
    scanf("%d%d%d",&N,&M,&K);
    init();
    for(int i=0; i<M; i++) {
        scanf("%d%d",&from,&to);
        addEdge(from,to);
        addEdge(to,from);
    }
    for(int i=0; i<K; i++) {
        scanf("%d",&from);
        fill(mark.begin(),mark.end(),false);
        mark[from]=true;
        int cnt=0;
        for(int from=1; from<=N; from++) {
            if(mark[from]) continue;
            DFS(from);
            cnt++;
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}

/*
3 2 3
1 2
1 3
1 2 3

1
0
0
*/