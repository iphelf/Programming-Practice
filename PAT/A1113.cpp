#include<cstdio>
#include<algorithm>
#include<numeric>

using namespace std;

const int MAXN=1e5;

int N;
long long arr[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) scanf("%lld",&arr[i]);
        sort(arr,arr+N);
        printf("%d %lld\n",
               N%2,
               accumulate(arr+N/2,arr+N,0)-accumulate(arr,arr+N/2,0));
    }
    return 0;
}

/*
10
23 8 10 99 46 2333 46 1 666 555
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85

0 3611
1 9359
*/
