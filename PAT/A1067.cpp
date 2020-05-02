#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=1e5;

int N,a[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0; i<N; i++) {
        if(a[i]==i) continue;
        if(i>0) {
            swap(a[0],a[i]);
            cnt++;
        }
        while(a[0]!=0) {
            swap(a[0],a[a[0]]);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

/*
10
3 5 7 2 6 4 9 0 8 1

9
*/
