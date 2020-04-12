#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXL=1e4,MAXC=2e2,INF=0x3f3f3f3f;
typedef long long ll;

int N,M,L,nId,id[MAXC+1],a[MAXL+1],dp[MAXL+1];
// dp[len]=minimum tail of ascending sequence of length `len`
// for a[i]: *upper_bound(dp,dp+1+L,a[i])=a[i]

void init() {
    nId=0;
    memset(id,-1,sizeof id);
    memset(dp,INF,sizeof dp);
    dp[0]=-1;
}
int getId(int c) {
    if(id[c]==-1) return id[c]=nId++;
    else return id[c];
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        init();
        int c;
        for(int i=0; i<M; i++) {
            scanf("%d",&c);
            getId(c);
        }
        scanf("%d",&L);
        for(int i=0; i<L; i++) {
            scanf("%d",&c);
            a[i]=id[c];
            if(a[i]==-1) continue;
            *upper_bound(dp,dp+1+L,a[i])=a[i];
        }
        for(int len=L; len>=0; len--) if(dp[len]!=INF) {
                printf("%d\n",len);
                break;
            }
    }
    return 0;
}

/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

7
*/
