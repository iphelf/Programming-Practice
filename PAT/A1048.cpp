#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN=1e5,MAXF=5e2,MAXM=1e3;

int N,M,cnt[MAXF+1];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        int face;
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<N; i++) {
            scanf("%d",&face);
            cnt[face]++;
        }
        bool found=false;
        for(face=1; face<=MAXF; face++) if(cnt[face]) {
                if(M-face>MAXF) continue;
                if(cnt[M-face]==0) continue;
                if(face==M-face && cnt[face]<2) continue;
                found=true;
                break;
            }
        if(found) printf("%d %d\n",face,M-face);
        else puts("No Solution");
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
