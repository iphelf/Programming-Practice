#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=1e5;

int N,P;
long long a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&P);
    for(int i=0; i<N; i++) scanf("%d",&a[i]);
    sort(a,a+N);
    int ans=1;
    long long *ub;
    for(int l=0; l<N-1; l++) {
        ub=upper_bound(a+l+1,a+N,a[l]*P);
        ans=max(ans,int(ub-&a[l]));
    }
    printf("%d\n",ans);
    return 0;
}

/*
10 8
2 3 20 4 5 1 6 7 8 9

8
*/
