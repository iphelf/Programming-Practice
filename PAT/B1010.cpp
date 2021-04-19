#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

#define mp(x,y) make_pair((x),(y))
typedef pair<int,int> pii;
const int MAXN=1e5;
int f[MAXN+1],p[MAXN+1];

int main(void) {
//    freopen("in.txt","r",stdin);
    int N=0;
    while(~scanf("%d%d",&f[N],&p[N])) N++;
    queue<pii> q;
    for(int i=0;i<N;i++)
        if(p[i]!=0) q.push(mp(f[i]*p[i],p[i]-1));
    if(q.empty()) puts("0 0");
    else{
        while(!q.empty()){
            printf("%d %d",q.front().first,q.front().second);
            q.pop();
            if(q.empty()) putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}

/*
3 4 -5 2 6 1 -2 0

12 3 -10 1 6 0
*/

