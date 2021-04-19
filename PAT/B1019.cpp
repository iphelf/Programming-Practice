#include<stdio.h>
#include<algorithm>
using namespace std;

int N;

int toi(char s[5]){
    int n=0;
    for(int i=0;i<4;i++) n=n*10+s[i]-'0';
    return n;
}

void solve(){
    char s[5];
    sprintf(s,"%04d",N);
    sort(s,s+4);
    if(s[0]==s[3]){
        printf("%s - %s = 0000\n",s,s);
        return;
    }
    while(true){
        sort(s,s+4);
        int a=toi(s);
        reverse(s,s+4);
        int b=toi(s);
        printf("%04d - %04d = %04d\n",b,a,b-a);
        if(b-a==6174) return;
        sprintf(s,"%04d",b-a);
    }
}

int main(void){
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) solve();
    return 0;
}

/*
6767
2222

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
2222 - 2222 = 0000
*/

