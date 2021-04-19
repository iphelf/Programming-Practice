#include<stdio.h>
#include<string.h>
using namespace std;

char s[100+1];

bool check(char *s) {
    int len=strlen(s);
    int n=0,x=0,y=0;
    int i;
    for(i=0;i<len;i++){
        if(s[i]=='A') x++;
        else if(s[i]=='P') break;
        else return false;
    }
    if(i==len) return false;
    for(i+=1;i<len;i++){
        if(s[i]=='A') n++;
        else if(s[i]=='T') break;
        else return false;
    }
    if(i==len || n<1) return false;
    for(i+=1;i<len;i++){
        if(s[i]=='A') y++;
        else return false;
    }
    if(y!=n*x) return false;
    return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",&s);
        if(check(s)) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

YES
YES
YES
YES
NO
NO
NO
NO
*/
