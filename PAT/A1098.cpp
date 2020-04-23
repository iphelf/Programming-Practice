#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e2;

int N,a[MAXN],b[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) scanf("%d",&a[i]);
        for(int i=0; i<N; i++) scanf("%d",&b[i]);
        int end=N;
        while(end>0 && a[end-1]==b[end-1]) end--;
        if(is_sorted(b,b+end)) {
            puts("Insertion Sort");
            for(end=1; end<N&&b[end-1]<=b[end]; end++);
            while(end>0 && b[end-1]>b[end]) {
                swap(b[end-1],b[end]);
                end--;
            }
        } else {
            puts("Heap Sort");
            sort(a,a+N);
            end=N;
            while(end>0 && a[end-1]==b[end-1]) end--;
            make_heap(b,b+end);
            pop_heap(b,b+end);
        }
        for(int i=0; i<N; i++) printf("%d%c",b[i],i==N-1?'\n':' ');
    }
    return 0;
}

/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9

Insertion Sort
1 2 3 5 7 8 9 4 6 0
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/
