#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN=1e5,MOD=1e9+7;

int N,lP[MAXN],rT[MAXN];
char s[MAXN+1];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%s",s);
    N=strlen(s);
    lP[0]=s[0]=='P'?1:0;
    rT[N-1]=s[N-1]=='T'?1:0;
    for(int i=1; i<N; i++) lP[i]=lP[i-1]+(s[i]=='P'?1:0);
    for(int i=N-2; i>=0; i--) rT[i]=rT[i+1]+(s[i]=='T'?1:0);
    long long ans=0;
    for(int i=1; i<N-1; i++) if(s[i]=='A')
            ans=(ans+((long long)(lP[i])*rT[i])%MOD)%MOD;
    printf("%lld\n",ans);
    return 0;
}

/*
APPAPT

2
*/
