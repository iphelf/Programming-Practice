#include<cstdio>
#include<algorithm>
#include<functional>

using namespace std;

const int MAXN=1e3;

int N,heap[MAXN],path[MAXN],cnt;

void dfs(int o) {
    path[cnt++]=heap[o];
    int lc=o*2+1,rc=o*2+2;
    if(lc>=N && rc>=N)
        for(int i=0; i<cnt; i++) printf("%d%c",path[i],i==cnt-1?'\n':' ');
    else {
        if(rc<N) dfs(rc);
        if(lc<N) dfs(lc);
    }
    cnt--;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) scanf("%d",&heap[i]);
        cnt=0;
        dfs(0);
        if(is_heap(heap,heap+N,less<int>())) puts("Max Heap");
        else if(is_heap(heap,heap+N,greater<int>())) puts("Min Heap");
        else puts("Not Heap");
    }
    return 0;
}

/*
8
98 72 86 60 65 12 23 50
8
8 38 25 58 52 82 70 60
8
10 28 15 12 34 9 8 56

98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap
8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap
10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap
*/
