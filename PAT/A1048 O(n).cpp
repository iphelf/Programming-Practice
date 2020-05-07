#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e5;

int N,M,a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        for(int i=0; i<N; i++) scanf("%d",&a[i]);
        sort(a,a+N);
        int i=0,j=N-1;
        while(i<j) {
            if(a[i]+a[j]<M) i++;
            else if(a[i]+a[j]>M) j--;
            else break;
        }
        if(a[i]+a[j]!=M || i>=j) puts("No Solution");
        else printf("%d %d\n",a[i],a[j]);
    }
    return 0;
}

/*
8 15
1 2 8 7 2 4 11 15
7 14
1 8 7 2 4 11 15

4 11
No Solution
*/
