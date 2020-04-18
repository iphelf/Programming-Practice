#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

const int MAXN=30,MAXS=20;

int N,lc[MAXN+1],rc[MAXN+1],iIn[MAXN+1],iPre[MAXN+1];
vector<int> in,post,pre;

void DFS(int preRt,int l,int r) {
    int rt=pre[preRt],inRt=iIn[rt];
    if(inRt>l) DFS(preRt+1,l,inRt-1);
    if(inRt<r) DFS(preRt+1+inRt-l,inRt+1,r);
    post.push_back(rt);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d\n",&N);
    char op[MAXS+1];
    stack<int> s;
    int curr,root=-1;
    memset(lc,-1,sizeof lc);
    memset(rc,-1,sizeof rc);
    for(int i=2*N; i>=1; i--) {
        scanf("%s",op);
        if(op[1]=='u') {
            scanf("%d",&curr);
            if(root==-1) root=curr;
            iPre[curr]=pre.size();
            pre.push_back(curr);
            s.push(curr);
        } else {
            curr=s.top();
            iIn[curr]=in.size();
            in.push_back(curr);
            s.pop();
        }
    }
    DFS(0,0,N-1);
    for(int i=0; i<N; i++) printf("%d%c",post[i],i==N-1?'\n':' ');
    return 0;
}

/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

3 4 2 6 5 1
*/
