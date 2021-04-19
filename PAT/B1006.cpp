#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;

int main(void) {
//    freopen("in.txt","r",stdin);
    int N;
    while(~scanf("%d",&N)){
        for(int i=N/100;i>0;i--) putchar('B');
        N=N%100;
        for(int i=N/10;i>0;i--) putchar('S');
        N=N%10;
        for(int i=1;i<=N;i++) putchar('0'+i);
        putchar('\n');
    }
    return 0;
}

/*
234
23

BBSSS1234
SS123
*/

