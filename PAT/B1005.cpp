#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;

const int MAXN=100,MAXD=1e7;
int N,a[MAXN+1];
bool covered[MAXD];

void cover(int n){
    while(n>1){
        if(n&1) n=(n-1)/2*3+2;
        else n=n/2;
        covered[n]=true;
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    memset(covered,false,sizeof covered);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        cover(a[i]);
    }
    sort(a,a+N);
    stack<int> s;
    for(int i=0;i<N;i++) if(!covered[a[i]]) s.push(a[i]);
    while(!s.empty()){
        printf("%d",s.top());
        s.pop();
        if(s.empty()) putchar('\n');
        else putchar(' ');
    }
    return 0;
}

/*
6
3 5 6 7 8 11

7 6
*/
