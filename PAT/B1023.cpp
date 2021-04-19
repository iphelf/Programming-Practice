#include<stdio.h>
#include<string>
using namespace std;

int main(void){
//    freopen("in.txt","r",stdin);
    int cnt[10];
    for(int i=0;i<10;i++) scanf("%d",&cnt[i]);
    if(cnt[0]>0){
        for(int i=1;i<10;i++) if(cnt[i]>0){
            putchar('0'+i);
            cnt[i]--;
            break;
        }
        for(int i=0;i<cnt[0];i++) putchar('0');
    }
    for(int i=1;i<10;i++) while(cnt[i]>0){ putchar('0'+i); cnt[i]--; }
    putchar('\n');
    return 0;
}

/*
2 2 0 0 0 3 0 0 1 0

10015558
*/

