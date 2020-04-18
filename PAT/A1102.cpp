#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>

using namespace std;

const int MAXN=10;
int N,lc[MAXN],rc[MAXN];
bool isRoot[MAXN];
vector<int> in,level;

void dfsIn(int rt) {
    if(rt==-1) return;
    dfsIn(lc[rt]);
    in.push_back(rt);
    dfsIn(rc[rt]);
}

void bfsLevel(int rt) {
    queue<int> q;
    q.push(rt);
    while(!q.empty()) {
        rt=q.front();
        q.pop();
        if(rt==-1) continue;
        level.push_back(rt);
        q.push(lc[rt]);
        q.push(rc[rt]);
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    memset(isRoot,true,sizeof isRoot);
    memset(lc,-1,sizeof lc);
    memset(rc,-1,sizeof rc);
    char sLc[5],sRc[5];
    for(int i=0; i<N; i++) {
        scanf(" %s %s",sRc,sLc);
        if(sLc[0]!='-') {
            lc[i]=atoi(sLc);
            isRoot[lc[i]]=false;
        }
        if(sRc[0]!='-') {
            rc[i]=atoi(sRc);
            isRoot[rc[i]]=false;
        }
    }
    int root=0;
    for(int i=0; i<N; i++) if(isRoot[i]) {
            root=i;
            break;
        }
    bfsLevel(root);
    dfsIn(root);
    for(int i=0; i<N; i++) printf("%d%c",level[i],i==N-1?'\n':' ');
    for(int i=0; i<N; i++) printf("%d%c",in[i],i==N-1?'\n':' ');
    return 0;
}

/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/
