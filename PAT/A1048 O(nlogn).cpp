#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=1e5;

int N,M,a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        for(int i=0; i<N; i++) scanf("%d",&a[i]);
        sort(a,a+N);
        bool found=false;
        for(int i=0,*lb; i<N-1; i++) {
            lb=lower_bound(a+i+1,a+N,M-a[i]);
            if(lb==a+N || a[i]+*lb!=M) continue;
            found=true;
            printf("%d %d\n",a[i],*lb);
            break;
        }
        if(!found) puts("No Solution");
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
