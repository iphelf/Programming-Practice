#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

const int MAXN=1e4;
typedef map<int,int> mii;

int N,in[MAXN],*pIn[MAXN],pre[MAXN],val[MAXN];
mii m;

int lca(int *inU,int *inV,int n,int *in,int *pre) {
    int rt=pre[0],*inRt=pIn[rt];
    int nL=inRt-in,nR=in+n-1-inRt;
    if(inU<inRt && inV<inRt) return lca(inU,inV,nL,in,pre+1);
    if(inU>inRt && inV>inRt) return lca(inU,inV,nR,inRt+1,pre+1+nL);
    return rt;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,k,v;
    scanf("%d%d",&M,&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&v);
        k=m.size();
        m[v]=k;
        val[k]=v;
        in[i]=k;
        pIn[in[i]]=&in[i];
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&v);
        pre[i]=m[v];
    }
    for(int i=0; i<M; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        mii::iterator itU=m.find(u);
        mii::iterator itV=m.find(v);
        if(itU==m.end() && itV==m.end())
            printf("ERROR: %d and %d are not found.",u,v);
        else if(itU==m.end())
            printf("ERROR: %d is not found.",u);
        else if(itV==m.end())
            printf("ERROR: %d is not found.",v);
        else {
            int ans=val[lca(pIn[m[u]],pIn[m[v]],N,in,pre)];
            if(ans==u)
                printf("%d is an ancestor of %d.",u,v);
            else if(ans==v)
                printf("%d is an ancestor of %d.",v,u);
            else
                printf("LCA of %d and %d is %d.",u,v,ans);
        }
        putchar('\n');
    }
    return 0;
}

/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99

LCA of 2 and 6 is 3.
8 is an ancestor of 1.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/
