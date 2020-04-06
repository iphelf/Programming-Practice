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

const int MAXN=1e4,MAXE=MAXN*2;
struct Edge {
    int to,next;
};

int N,head[MAXN+1],nEdge,d[MAXN+1];
Edge edge[MAXE];
vector<bool> mark(MAXN+1);

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
    for(int i=head[from]; ~i; i=edge[i].next) {
        to=edge[i].to;
        if(mark[to]) continue;
        DFS(to);
    }
}
void DFS(int from,int depth) {
    mark[from]=true;
    d[from]=depth;
    int to;
    for(int i=head[from]; ~i; i=edge[i].next) {
        to=edge[i].to;
        if(mark[to]) continue;
        DFS(to,depth+1);
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        init();
        int from,to;
        for(int i=0; i<N-1; i++) {
            scanf("%d%d",&from,&to);
            addEdge(from,to);
            addEdge(to,from);
        }
        fill(mark.begin(),mark.end(),false);
        int cnt=0;
        for(int from=1; from<=N; from++) {
            if(mark[from]) continue;
            DFS(from);
            cnt++;
        }
        if(cnt>1) {
            printf("Error: %d components\n",cnt);
            continue;
        }
        fill(mark.begin(),mark.end(),false);
        DFS(1,0);
        from=max_element(d+1,d+1+N)-d;
        set<int> ans;
        for(int i=1; i<=N; i++) if(d[i]==d[from]) ans.insert(i);
        fill(mark.begin(),mark.end(),false);
        DFS(from,0);
        to=max_element(d+1,d+1+N)-d;
        for(int i=1; i<=N; i++) if(d[i]==d[to]) ans.insert(i);
        for(set<int>::iterator it=ans.begin(); it!=ans.end(); it++)
            printf("%d\n",*it);
    }
    return 0;
}

/*
5
1 2
1 3
1 4
2 5
5
1 3
1 4
2 5
3 4

3
4
5
Error: 2 components
*/