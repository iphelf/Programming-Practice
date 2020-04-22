#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

const int MAXN=1e3;
typedef map<int,int> mii;

int N,pre[MAXN],post[MAXN],val[MAXN],lc[MAXN],rc[MAXN];
mii m;
bool mirror;

bool isBST(int n,int *pre,int *post) {
    int rt=pre[0],*rl,*rr,*end=pre+n;
    post[n-1]=rt;
    if(!mirror) {
        for(rl=pre+1; rl!=end && val[*rl]<val[rt]; rl++);
        for(rr=rl; rr!=end && val[*rr]>=val[rt]; rr++);
    } else {
        for(rl=pre+1; rl!=end && val[*rl]>=val[rt]; rl++);
        for(rr=rl; rr!=end && val[*rr]<val[rt]; rr++);
    }
    if(rr!=end) return false;
    int nL=rl-pre-1,nR=n-1-nL;
    return (nL<=0 || isBST(nL,pre+1,post))
           && (nR<=0 || isBST(nR,pre+1+nL,post+nL));
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        int v;
        m.clear();
        for(int k=0; k<N; k++) {
            scanf("%d",&v);
            m[v]=k;
            pre[k]=k;
            val[k]=v;
        }
        if((mirror=false,isBST(N,pre,post))||(mirror=true,isBST(N,pre,post))) {
            puts("YES");
            for(int i=0; i<N; i++) printf("%d%c",val[post[i]],i==N-1?'\n':' ');
        } else puts("NO");
    }
    return 0;
}

/*
7
8 6 5 7 10 8 11
7
8 10 11 8 6 7 5
7
8 6 8 5 10 9 11

YES
5 7 6 8 11 10 8
YES
11 8 10 7 5 6 8
NO
*/
