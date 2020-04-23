#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=1e3;

int N,in[MAXN],val[MAXN],cbt[MAXN];
map<int,int> m;

void fillCBT(int iRt,int n,int *in) {
    int iLc=iRt*2+1,iRc=iRt*2+2;
    int h=ceil(log2(n+1));
    if(h==1) {
        cbt[iRt]=in[0];
        return;
    }
    int b=n-(1<<(h-1))+1;
    int nL=(1<<(h-2))-1+min(1<<(h-2),b),nR=n-1-nL; // 1<<(-1) => 0
    cbt[iRt]=in[nL];
    if(nL>0) fillCBT(iLc,nL,in);
    if(nR>0) fillCBT(iRc,nR,in+nL+1);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) {
            scanf("%d",&val[i]);
            in[i]=i;
        }
        sort(val,val+N);
        fillCBT(0,N,in);
        for(int i=0; i<N; i++)
            printf("%d%c",val[cbt[i]],i==N-1?'\n':' ');
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 0

6 3 8 1 5 7 9 0 2 4
*/
