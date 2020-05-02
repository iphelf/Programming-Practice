#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=1e5;

int nA,nB;
long long a[MAXN],b[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&nA);
    for(int i=0; i<nA; i++) scanf("%lld",&a[i]);
    sort(a,a+nA);
    scanf("%d",&nB);
    for(int i=0; i<nB; i++) scanf("%lld",&b[i]);
    sort(b,b+nB);
    long long ans=0;
    for(int i=0,j=0; i<nA && j<nB && a[i]<0 && b[j]<0; i++,j++)
        ans+=a[i]*b[j];
    for(int i=nA-1,j=nB-1; i>=0 && j>=0 && a[i]>0 && b[j]>0; i--,j--)
        ans+=a[i]*b[j];
    printf("%lld\n",ans);
    return 0;
}

/*
4
1 2 4 -1
4
7 6 -2 -3

43
*/
