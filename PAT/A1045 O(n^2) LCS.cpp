#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int MAXL=1e4,MAXC=2e2;
typedef long long ll;

int N,M,L,a[MAXL+1],b[MAXL+1],fav[MAXC+1],dp[MAXL+1][MAXL+1];
map<int,int> cnt;

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        for(int i=0; i<M; i++) {
            scanf("%d",&fav[i]);
            cnt[fav[i]]=0;
        }
        scanf("%d",&L);
        int n=1;
        for(int i=0; i<L; i++) {
            scanf("%d",&a[n]);
            map<int,int>::iterator it=cnt.find(a[n]);
            if(it==cnt.end()) continue;
            it->second++;
            n++;
        }
        n=1;
        for(int i=0; i<M; i++) {
            for(int j=cnt[fav[i]]; j>0; j--) {
                b[n]=fav[i];
                n++;
            }
        }
        n--;
//        for(int i=1; i<=n; i++) printf("%d%c",a[i],i==n?'\n':' ');
//        for(int i=1; i<=n; i++) printf("%d%c",b[i],i==n?'\n':' ');
        for(int i=0; i<=n; i++) dp[0][i]=dp[i][0]=0;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
                dp[i][j]=max(dp[i-1][j-1]+(a[i]==b[j]?1:0),
                             max(dp[i-1][j],dp[i][j-1]));
        printf("%d\n",dp[n][n]);
    }
    return 0;
}

/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

7
*/
