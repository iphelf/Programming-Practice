#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

const int MAXN=1e6;
bool isPrime[MAXN+1];
vector<int> prime;

int main(void){
//    freopen("in.txt","r",stdin);
    int M,N;
    scanf("%d%d",&M,&N);
    memset(isPrime,true,sizeof isPrime);
    isPrime[1]=false;
    prime.push_back(0);
    for(int i=2;i<=MAXN;i++) if(isPrime[i]){
        for(int j=i*2;j<=MAXN;j+=i) isPrime[j]=false;
        prime.push_back(i);
    }
    int len=N-M+1;
    for(int i=0;i<len;i++)
        printf("%d%c",prime[i+M],((i%10==9||i==len-1)?'\n':' '));
    return 0;
}

/*
5 27

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

