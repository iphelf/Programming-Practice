#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int MAXL=1e4,MAXC=2e2;
typedef long long ll;

int N,M,L,a[MAXL+1],b[MAXL+1],fav[MAXC+1],dp[2][MAXL+1];
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
        for(int i=0; i<=n; i++) dp[0][i]=0;
        dp[1][0]=0;
        for(int i=1,curr,prev; i<=n; i++) for(int j=1; j<=n; j++) {
                curr=i%2;
                prev=1-curr;
                dp[curr][j]=max(dp[prev][j-1]+(a[i]==b[j]?1:0),
                                max(dp[prev][j],dp[curr][j-1]));
            }
        printf("%d\n",dp[n%2][n]);
    }
    return 0;
}

/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

7
*/
