#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=1e2;
typedef long long ll;

int N;
vector<int> child[MAXN],path;
ll S,w[MAXN],length;

bool cmp(int l,int r) {
    return w[l]>w[r];
}

void dfs(int rt) {
    path.push_back(rt);
    length+=w[rt];
    if(child[rt].empty()) {
        if(length==S) for(int i=0; i<path.size(); i++)
                printf("%d%c",w[path[i]],i==path.size()-1?'\n':' ');
    } else for(int c:child[rt]) dfs(c);
    path.pop_back();
    length-=w[rt];
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,r,c,K;
    scanf("%d%d%d",&N,&M,&S);
    for(int i=0; i<N; i++) scanf("%lld",&w[i]);
    for(int i=0; i<M; i++) {
        scanf("%d%d",&r,&K);
        for(int j=0; j<K; j++) {
            scanf("%d",&c);
            child[r].push_back(c);
        }
        sort(child[r].begin(),child[r].end(),cmp);
    }
    dfs(0);
    return 0;
}

/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19

10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
*/
