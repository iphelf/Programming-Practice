#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;

int main(void){
//    freopen("in.txt","r",stdin);
    char s[100+1];
    char name[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    scanf("%s",s);
    int len=strlen(s);
    int ans=0;
    for(int i=0;i<len;i++) ans+=s[i]-'0';
    stack<int> d;
    while(ans>0){
        d.push(ans%10);
        ans/=10;
    }
    while(!d.empty()){
        int curr=d.top();
        d.pop();
        printf("%s",name[curr]);
        if(d.empty()) putchar('\n');
        else putchar(' ');
    }
    return 0;
}

/*
1234567890987654321123456789

yi san wu
*/
