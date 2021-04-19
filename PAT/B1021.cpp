#include<stdio.h>
#include<string.h>
using namespace std;

const int MAXN=1e3;

int main(void){
//    freopen("in.txt","r",stdin);
    int cnt[10];
    memset(cnt,0,sizeof cnt);
    char s[MAXN+1];
    scanf("%s",s);
    int N=strlen(s);
    for(int i=0;i<N;i++) cnt[s[i]-'0']++;
    for(int i=0;i<10;i++) if(cnt[i]>0) printf("%d:%d\n",i,cnt[i]);
    return 0;
}

/*
100311

0:2
1:3
3:1
*/

