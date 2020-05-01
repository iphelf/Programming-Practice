#include<cstdio>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

const int MAXN=1e4;

int N;
int len[MAXN];

int add(int l,int r) {
    return (l+r)/2;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&len[i]);
    sort(len,len+N);
    printf("%d\n",
           accumulate(len+1,len+N,len[0],add));
    return 0;
}

/*
8
10 15 12 3 4 13 1 15

14
*/
