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

const int MAXN=2e2,MAXE=MAXN*MAXN,INF=0x3f3f3f3f;
struct Edge {
    int to,cost,next;
};

int N,S,T,w[MAXN],nEdge,head[MAXN],d[MAXN];
Edge edge[MAXE];
bool mark[MAXN];
map<string,int> m;
string name[MAXN];
vi pre[MAXN];
int ansN,ansCost,ansWeight;
double ansAvgWeight;
stack<int> ansPath;
stack<int> path;

int getId(string s) {
    map<string,int>::iterator it=m.find(s);
    if(it!=m.end()) return it->second;
    int id=m.size();
    m[s]=id;
    name[id]=s;
    return id;
}
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
    memset(d,INF,sizeof d);
    memset(mark,false,sizeof mark);
    priority_queue< pii,vector<pii>,greater<pii> > pq;
    d[0]=0;
    pq.push(mp(0,0));
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
            if(d[to]<d[from]+cost) continue;
            if(d[to]==d[from]+cost)
                pre[to].push_back(from);
            else {
                d[to]=d[from]+cost;
                pre[to].clear();
                pre[to].push_back(from);
                pq.push(mp(d[to],to));
            }
        }
    }
}
void DFS(int from,int weight,int number) {
    path.push(from);
    if(from==S) {
        ansN++;
        double avgWeight=double(weight)/number;
        if(mp(weight,avgWeight)>mp(ansWeight,ansAvgWeight)) {
            ansWeight=weight;
            ansAvgWeight=avgWeight;
            ansPath=path;
        }
    } else {
        for(int &to:pre[from])
            DFS(to,weight+w[to],number+1);
    }
    path.pop();
}

int main(void) {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int K,from,to,cost,weight;
    string sFrom,sTo;
    cin>>N>>K>>sFrom;
    init();
    w[getId(sFrom)]=0;
    for(int i=1; i<N; i++) {
        cin>>sFrom>>weight;
        w[getId(sFrom)]=weight;
    }
    S=0;
    T=getId("ROM");
    for(int i=0; i<K; i++) {
        cin>>sFrom>>sTo>>cost;
        from=getId(sFrom);
        to=getId(sTo);
        addEdge(from,to,cost);
        addEdge(to,from,cost);
    }
    Dijkstra();
    ansCost=d[T];
    ansN=0;
    ansWeight=0;
    DFS(T,w[T],0);
    cout<<ansN<<' '<<ansCost<<' '<<ansWeight<<' '<<int(ansAvgWeight)<<endl;
    while(!ansPath.empty()) {
        cout<<name[ansPath.top()];
        ansPath.pop();
        if(ansPath.empty()) cout<<endl;
        else cout<<"->";
    }
    return 0;
}

/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

3 3 195 97
HZH->PRS->ROM
*/
