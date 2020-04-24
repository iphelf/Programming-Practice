#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>

using namespace std;

const int MAXN=1e3;

int N,heap[MAXN],cnt;

void dfs(int o) {
    if(o>=N) return;
    int lc=o*2+1,rc=o*2+2;
    dfs(lc);
    dfs(rc);
    printf("%d%c",heap[o],cnt==N-1?'\n':' ');
    cnt++;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M;
    scanf("%d%d",&M,&N);
    while(M--) {
        for(int i=0; i<N; i++) scanf("%d",&heap[i]);
        if(is_heap(heap,heap+N,less<int>())) puts("Max Heap");
        else if(is_heap(heap,heap+N,greater<int>())) puts("Min Heap");
        else puts("Not Heap");
        cnt=0;
        dfs(0);
    }
    return 0;
}

/*
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56

Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
*/
