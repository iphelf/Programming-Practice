#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN=1e2;

int N,cnt[MAXN],maxD;
vector<int> child[MAXN];

void DFS(int d,int rt) {
    maxD=max(d,maxD);
    if(child[rt].empty()) {
        cnt[d]++;
        return;
    }
    for(int i=0; i<child[rt].size(); i++)
        DFS(d+1,child[rt][i]);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,n,rt,ch,K;
    while(~scanf("%d%d",&N,&M) && N!=0) {
        for(int i=0; i<N; i++) child[i].clear();
        for(int i=0; i<M; i++) {
            scanf("%d%d",&rt,&K);
            for(int j=0; j<K; j++) {
                scanf("%d",&ch);
                child[rt].push_back(ch);
            }
        }
        maxD=0;
        DFS(0,1);
        for(int i=0; i<=maxD; i++)
            printf("%d%c",cnt[i],i==maxD?'\n':' ');
    }
    return 0;
}

/*
2 1
01 1 02

0 1
*/
