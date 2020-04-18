#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

const int MAXN=1e3;

int N,lc[MAXN],rc[MAXN],val[MAXN],cnt[MAXN+1],maxD;

void push(int d,int rt,int k) {
    d++;
    maxD=max(maxD,d);
    if(val[k]<=val[rt]) {
        if(lc[rt]==-1) {
            lc[rt]=k;
            cnt[d]++;
        } else push(d,lc[rt],k);
    } else {
        if(rc[rt]==-1) {
            rc[rt]=k;
            cnt[d]++;
        } else push(d,rc[rt],k);
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    int v,rt=-1;
    memset(lc,-1,sizeof lc);
    memset(rc,-1,sizeof rc);
    memset(cnt,0,sizeof cnt);
    maxD=1;
    cnt[1]=1;
    for(int k=0; k<N; k++) {
        scanf("%d",&v);
        val[k]=v;
        if(rt==-1) rt=k;
        else push(1,rt,k);
    }
    printf("%d + %d = %d\n",cnt[maxD],cnt[maxD-1],cnt[maxD]+cnt[maxD-1]);
    return 0;
}

/*
9
25 30 42 16 20 20 35 -5 28

2 + 4 = 6
*/
