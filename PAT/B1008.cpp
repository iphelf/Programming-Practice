#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=100;
int a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    int N;
    long long M;
    scanf("%d%lld",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    M=M%N;
    reverse(a,a+N-M);
    reverse(a+N-M,a+N);
    reverse(a,a+N);
    for(int i=0;i<N;i++) printf("%d%c",a[i],i==N-1?'\n':' ');
    return 0;
}

/*
6 2
1 2 3 4 5 6

5 6 1 2 3 4
*/

