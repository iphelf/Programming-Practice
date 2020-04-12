#include<iostream>
#include<cstring>
#include<algorithm>
#include<numeric>

using namespace std;

const int MAXN=1e4,MAXV=1e2;

int N,V,c[MAXN+1];
bool dp[MAXN+1][MAXV+1];

void ZeroOnePack(bool prev[MAXV+1],bool curr[MAXV+1],int cost) {
    for(int v=0; v<cost; v++)
        curr[v]=prev[v];
    for(int v=cost; v<=V; v++)
        curr[v]=(prev[v]|prev[v-cost]);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&V)) {
        for(int i=1; i<=N; i++) scanf("%d",&c[i]);
        sort(c+1,c+1+N);
        reverse(c+1,c+1+N);
        fill(dp[0],dp[0]+MAXV+1,false);
        dp[0][0]=true;
        for(int i=1; i<=N; i++)
            ZeroOnePack(dp[i-1],dp[i],c[i]);
        if(dp[N][V]==false) {
            puts("No Solution");
            continue;
        }
        for(int i=N-1,v=V; i>=0; i--) {
            if(v>=c[i+1] && dp[i][v-c[i+1]]) {
                v-=c[i+1];
                printf("%d%c",c[i+1],v==0?'\n':' ');
            }
        }
    }
    return 0;
}

/*
8 9
5 9 8 7 2 3 4 1
4 8
7 2 4 3

1 3 5
No Solution
*/
