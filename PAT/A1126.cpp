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

const int MAXN=5e2;

int N,deg[MAXN+1];
bool d[MAXN+1][MAXN+1];
bool mark[MAXN+1];

int DFS(int from) {
    mark[from]=true;
    int cnt=1;
    for(int to=1; to<=N; to++) if(d[from][to] && !mark[to]) cnt+=DFS(to);
    return cnt;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,from,to;
    while(~scanf("%d%d",&N,&M)) {
        memset(d,false,sizeof d);
        memset(deg,0,sizeof deg);
        for(int i=0; i<M; i++) {
            scanf("%d%d",&from,&to);
            d[from][to]=d[to][from]=true;
            deg[to]++;
            deg[from]++;
        }
        int cntOdd=0,cntEven=0;
        for(int i=1; i<=N; i++) {
            if(deg[i]%2==0) cntEven++;
            else cntOdd++;
            printf("%d%c",deg[i],i==N?'\n':' ');
        }
        memset(mark,false,sizeof mark);
        if(DFS(1)<N)
            puts("Non-Eulerian");
        else if(cntEven==N)
            puts("Eulerian");
        else if(cntOdd==2)
            puts("Semi-Eulerian");
        else
            puts("Non-Eulerian");
    }
    return 0;
}

/*
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3

2 4 4 4 4 4 2
Eulerian
2 4 4 4 3 3
Semi-Eulerian
3 3 4 3 3
Non-Eulerian
*/
