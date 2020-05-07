#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e5;

int N,P;
long long a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&P);
    for(int i=0; i<N; i++) scanf("%lld",&a[i]);
    sort(a,a+N);
    int i=0,j=0;
    int ans=1;
    while(i<N && j<N) {
        while(j<N && a[i]*P>=a[j]) j++;
        ans=max(ans,j-i);
        i++;
    }
    printf("%d\n",ans);
    return 0;
}

/*
10 8
2 3 20 4 5 1 6 7 8 9

8
*/
