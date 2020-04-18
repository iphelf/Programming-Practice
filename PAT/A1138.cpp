#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN=5e4,MAXV=1e7;

int N,pre[MAXN],*pPre[MAXV],in[MAXN],*pIn[MAXV],post0;

void dfs(int n,int *pre,int *in) {
    if(post0!=-1) return;
    int rt=pre[0],*pRt=pIn[rt];
    int nL=pRt-in,nR=in+n-1-pRt;
    if(nL>0) dfs(nL,pre+1,in);
    if(nR>0) dfs(nR,pre+1+nL,pRt+1);
    if(post0==-1) post0=rt;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&pre[i]);
        pPre[pre[i]]=&pre[i];
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&in[i]);
        pIn[in[i]]=&in[i];
    }
    post0=-1;
    dfs(N,pre,in);
    printf("%d\n",post0);
    return 0;
}

/*
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6

3
*/
