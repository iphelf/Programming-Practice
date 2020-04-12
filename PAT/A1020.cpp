#include<iostream>
#include<cstring>
#include<queue>
#include<utility>

using namespace std;

const int MAXN=30;
typedef pair<int,int> pii;
#define mp(x,y) make_pair((x),(y))
struct Range {
    int l,r;
};

int N,lc[MAXN+1],rc[MAXN+1],inOrder[MAXN],*pInOrder[MAXN+1],postOrder[MAXN];

void build(int n,int *in,int *post) {
    int rt=post[n-1],iRt=pInOrder[rt]-in;
    if(iRt==0) lc[rt]=-1;
    else {
        lc[rt]=post[iRt-1];
        build(iRt,in,post);
    }
    if(iRt==n-1) rc[rt]=-1;
    else {
        rc[rt]=post[n-2];
        build(n-1-iRt,in+iRt+1,post+iRt);
    }
}
void BFS(int rt) {
    queue<pii> q;
    q.push(mp(0,rt));
    int cnt=0;
    int d;
    while(!q.empty()) {
        d=q.front().first;
        rt=q.front().second;
        q.pop();
        cnt++;
        printf("%d%c",rt,cnt==N?'\n':' ');
        if(lc[rt]!=-1) q.push(mp(d+1,lc[rt]));
        if(rc[rt]!=-1) q.push(mp(d+1,rc[rt]));
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&postOrder[i]);
    for(int i=0; i<N; i++) {
        scanf("%d",&inOrder[i]);
        pInOrder[inOrder[i]]=&inOrder[i];
    }
    int root=postOrder[N-1];
    build(N,inOrder,postOrder);
    BFS(root);
    return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

4 1 6 3 5 7 2
*/
