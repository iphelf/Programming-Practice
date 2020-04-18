#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=30;
struct Segment {
    int l,r;
};

int N,pre[MAXN],iPre[MAXN+1],post[MAXN],iPost[MAXN+1],in[MAXN],nIn;
bool isUnique;

void dfs(const Segment &segPre,const Segment &segPost) {
    int rt=pre[segPre.l];
    if(segPre.l==segPre.r) {
        in[nIn++]=rt;
        return;
    }
    int lc=pre[segPre.l+1],rc=post[segPost.r-1];
    if(lc==rc) {
        isUnique=false;
        in[nIn++]=rt;
        dfs({segPre.l+1,segPre.r}, {segPost.l,segPost.r-1});
        return;
    }
    Segment segPreLc= {segPre.l+1,iPre[rc]-1};
    Segment segPreRc= {iPre[rc],segPre.r};
    Segment segPostLc= {segPost.l,iPost[lc]};
    Segment segPostRc= {iPost[lc]+1,segPost.r-1};
    dfs(segPreLc,segPostLc);
    in[nIn++]=rt;
    dfs(segPreRc,segPostRc);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) {
            scanf("%d",&pre[i]);
            iPre[pre[i]]=i;
        }
        for(int i=0; i<N; i++) {
            scanf("%d",&post[i]);
            iPost[post[i]]=i;
        }
        nIn=0;
        isUnique=true;
        dfs({0,N-1}, {0,N-1});
        if(isUnique) puts("Yes");
        else puts("No");
        for(int i=0; i<N; i++) printf("%d%c",in[i],i==N-1?'\n':' ');
    }
    return 0;
}

/*
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
4
1 2 3 4
2 4 3 1

Yes
2 1 6 4 7 3 5
No
2 1 3 4
*/
