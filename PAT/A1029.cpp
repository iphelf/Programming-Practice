#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e5,INF=0x3f3f3f3f3f3f3f3fLL;

int nA,nB;
long long a[MAXN+1],b[MAXN+1];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&nA);
    for(int i=0; i<nA; i++) scanf("%lld",&a[i]);
    scanf("%d",&nB);
    for(int i=0; i<nB; i++) scanf("%lld",&b[i]);
    a[nA]=b[nB]=INF;
    int i=0,j=0,half=(nA+nB+1)/2+1;
    while(i+j+2!=half) {
        if(a[i]>b[j]) j++;
        else i++;
    }
    printf("%lld\n",min(a[i],b[j]));
    return 0;
}

/*
4 11 12 13 14
5 9 10 15 16 17

13
*/
