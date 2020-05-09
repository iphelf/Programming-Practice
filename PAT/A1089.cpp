#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=100;

int N,a[MAXN],b[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) scanf("%d",&a[i]);
        for(int i=0; i<N; i++) scanf("%d",&b[i]);
        int i=0;
        while(i<N-1 && b[i+1]>=b[i]) i++;
        int j=i+1;
        while(j<N && a[j]==b[j]) j++;
        if(j==N) {
            puts("Insertion Sort");
            sort(b,b+i+2);
        } else {
            puts("Merge Sort");
            bool found=false;
            for(int len=2; len<=N; len*=2) {
                for(int l=0,r=len; l<N; l+=len,r=min(r+len,N))
                    if(!is_sorted(b+l,b+r)) {
                        sort(b+l,b+r);
                        found=true;
                    }
                if(found) break;
            }
            if(!found) sort(b,b+N);
        }
        for(i=0; i<N; i++) printf("%d%c",b[i],i==N-1?'\n':' ');
    }
    return 0;
}

/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

Insertion Sort
1 2 3 5 7 8 9 4 6 0
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
