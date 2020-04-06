#include<stdio.h>
#include<stack>
using namespace std;

void output(int n){
    if(n==0){puts("0");return;}
    if(n<0){
        putchar('-');
        n=-n;
    }
    stack<int> s;
    while(n>0){
        s.push(n%1000);
        n/=1000;
    }
    bool first=true;
    while(!s.empty()){
        if(first){
            printf("%d",s.top());
            first=false;
        }
        else printf("%03d",s.top());
        s.pop();
        if(s.empty()) putchar('\n');
        else putchar(',');
    }
}

int main(void){
//    freopen("in.txt","r",stdin);
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    output(c);
    return 0;
}

/*
-1000000 9

-999,991
*/