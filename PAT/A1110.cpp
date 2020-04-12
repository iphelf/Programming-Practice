#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN=20;
typedef vector<int> vi;

int N,lc[MAXN],rc[MAXN],id[MAXN];
bool isRoot[MAXN];

int getId(char s[5]) {
    if(s[0]=='-') return -1;
    else return atoi(s);
}
int getId(int i) { // Translate a node on CBT to a node on the given tree
    return id[i];
}
bool isCBT(int rt,int i) { // DFS on the given tree and CBT simultaneously
    if(i>=N) return rt==-1;
    if(rt==-1) return false;
    id[i]=rt;
    int iLc=i*2+1,iRc=i*2+2;
    return isCBT(lc[rt],iLc)&isCBT(rc[rt],iRc);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)) {
        char sLc[5],sRc[5];
        memset(isRoot,true,sizeof isRoot);
        for(int rt=0; rt<N; rt++) {
            scanf(" %s %s",sLc,sRc);
            lc[rt]=getId(sLc);
            if(lc[rt]!=-1) isRoot[lc[rt]]=false;
            rc[rt]=getId(sRc);
            if(rc[rt]!=-1) isRoot[rc[rt]]=false;
        }
        int root=0;
        for(int i=0; i<N; i++) if(isRoot[i]) {
                root=i;
                break;
            }
        if(isCBT(root,0))
            printf("YES %d\n",getId(N-1));
        else
            printf("NO %d\n",root);
    }
    return 0;
}

/*
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -

YES 8
NO 1
*/
