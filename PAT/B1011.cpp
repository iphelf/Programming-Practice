#include<stdio.h>
using namespace std;

long long A,B,C;
bool check(){
    if(A>0 && B>0 && C>0) return A>C-B;
    if(A<0 && B<0 && C<0) return A>C-B;
    if(A>0 && B>0 && C<0) return true;
    if(A<0 && B<0 && C>0) return false;
    return A+B>C;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        printf("Case #%d: ",I);
        scanf("%lld%lld%lld",&A,&B,&C);
        if(check()) puts("true");
        else puts("false");
    }
    return 0;
}

/*
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647

Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/

