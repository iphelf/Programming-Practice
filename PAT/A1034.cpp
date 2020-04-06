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

const int MAXE=2e3,MAXN=2e3;
struct Edge {
    int to,next;
};

int N,K,nEdge,head[MAXE],d[MAXN+1][MAXN+1],w[MAXN+1];
string name[MAXN+1];
bool mark[MAXN+1];
map<string,int> m;
Edge edge[MAXE];

void init() {
    nEdge=0;
    memset(d,0,sizeof d);
    memset(w,0,sizeof w);
    memset(head,-1,sizeof head);
    memset(mark,false,sizeof mark);
    m.clear();
}
void addEdge(int from,int to,int time) {
    if(d[from][to]==0) {
        edge[nEdge].to=to;
        edge[nEdge].next=head[from];
        head[from]=nEdge++;
    }
    d[from][to]+=time;
    w[from]+=time;
}
int getId(string s) {
    map<string,int>::iterator it=m.find(s);
    if(it!=m.end()) return it->second;
    int id=m.size();
    name[id]=s;
    m[s]=id;
    return id;
}
bool DFS(int source,pair<string,int> &gang) {
    int boss=source,cnt=0,sum=0;
    stack<int> s;
    cnt++;
    mark[source]=true;
    s.push(source);
    while(!s.empty()) {
        int from,to;
        from=s.top();
        s.pop();
        if(w[from]>w[boss]) boss=from;
        for(int iEdge=head[from]; ~iEdge; iEdge=edge[iEdge].next) {
            to=edge[iEdge].to;
            sum+=d[from][to];
            if(mark[to]) continue;
            cnt++;
            mark[to]=true;
            s.push(to);
        }
    }
    sum/=2;
    if(sum<=K || cnt<=2) return false;
    gang.first=name[boss];
    gang.second=cnt;
    return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string sFrom,sTo;
    int from,to,time;
    while(cin>>N>>K) {
        init();
        for(int i=0; i<N; i++) {
            cin>>sFrom>>sTo>>time;
            from=getId(sFrom);
            to=getId(sTo);
            addEdge(from,to,time);
            addEdge(to,from,time);
        }
        N=m.size();
        pair<string,int> gang;
        vector< pair<string,int> > v;
        for(int i=0; i<N; i++) {
            if(mark[i] || !DFS(i,gang)) continue;
            v.push_back(gang);
        }
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++) cout<<v[i].first<<' '<<v[i].second<<endl;
    }
    return 0;
}

/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

2
AAA 3
GGG 3
0
*/