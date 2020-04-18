#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=1e2;

int N,cnt[MAXN+1],maxD;
vector<int> child[MAXN+1];

void DFS(int d,int rt) {
    maxD=max(d,maxD);
    cnt[d]++;
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
        maxD=1;
        memset(cnt,0,sizeof cnt);
        DFS(1,1);
        int *ans=max_element(cnt+1,cnt+1+maxD);
        printf("%d %d\n",*ans,ans-cnt);
    }
    return 0;
}

/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

9 4
*/
