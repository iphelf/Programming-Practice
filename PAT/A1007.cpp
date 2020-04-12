#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e4;
typedef long long ll;

int N,lb[MAXN+1];
ll a[MAXN+1],dp[MAXN+1];
// dp[i]: max sum of sequence that ends at i
// dp[i]=max(a[i],dp[i-1]+a[i])

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        bool allNegative=true;
        for(int i=0; i<N; i++) {
            scanf("%lld",&a[i]);
            if(a[i]>=0) allNegative=false;
        }
        if(allNegative) {
            printf("0 %d %d\n",a[0],a[N-1]);
            continue;
        }
        dp[0]=a[0];
        lb[0]=0;
        for(int i=1; i<N; i++) {
            if(a[i]>=dp[i-1]+a[i]) {
                dp[i]=a[i];
                lb[i]=i;
            } else {
                dp[i]=dp[i-1]+a[i];
                lb[i]=lb[i-1];
            }
        }
        int r=max_element(dp,dp+N)-dp;
        int l=lb[r];
        printf("%lld %d %d\n",dp[r],a[l],a[r]);
    }
    return 0;
}

/*
10
-10 1 2 3 4 -5 -23 3 7 -21

10 1 4
*/
