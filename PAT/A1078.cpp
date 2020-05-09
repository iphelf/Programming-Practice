#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN=1e5;

int N,M,hash[MAXN];
bool isPrime[MAXN];

void getPrime() {
    memset(isPrime,true,sizeof isPrime);
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<MAXN; i++)
        if(isPrime[i])
            for(int j=i*2; j<MAXN; j+=i)
                isPrime[j]=false;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    getPrime();
    scanf("%d%d",&M,&N);
    while(!isPrime[M]) M++;
    int n,p;
    bool found;
    memset(hash,-1,sizeof hash);
    for(int i=0; i<N; i++) {
        scanf("%d",&n);
        found=false;
        for(int step=0; step<M; step++) {
            p=(n+step*step)%M;
            if(hash[p]==-1) {
                hash[p]=n;
                found=true;
                break;
            }
        }
        if(!found) putchar('-');
        else printf("%d",p);
        putchar(i==N-1?'\n':' ');
    }
    return 0;
}

/*
4 4
10 6 4 15

0 1 4 -
*/
