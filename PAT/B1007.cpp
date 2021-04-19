#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

const int MAXN=1e5;
bool isPrime[MAXN+1];
vector<int> prime;

int main(void) {
//    freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    memset(isPrime,true,sizeof isPrime);
    isPrime[1]=false;
    for(int i=2;i<=N;i++) if(isPrime[i]){
        for(int j=i*2;j<=N;j+=i) isPrime[j]=false;
        prime.push_back(i);
    }
    int ans=0;
    for(int i=1;i<prime.size();i++) if(prime[i]-prime[i-1]==2) ans++;
    printf("%d\n",ans);
    return 0;
}

/*
20

4
*/

