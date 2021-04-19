#include<stdio.h>
#include<stack>
using namespace std;

void solve(long long n,int r){
    if(n==0){
        puts("0");
        return;
    }
    stack<int> s;
    while(n>0){
        s.push(n%r);
        n/=r;
    }
    while(!s.empty()){
        putchar('0'+s.top());
        s.pop();
    }
}

int main(void){
//    freopen("in.txt","r",stdin);
    long long A,B;
    int R;
    scanf("%lld%lld%d",&A,&B,&R);
    solve(A+B,R);
    return 0;
}

/*
123 456 8

1103
*/

