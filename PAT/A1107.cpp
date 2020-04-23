#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=1e3,MAXM=1e3;

int N,M,fa[MAXN+1],cnt[MAXN+1];

int root(int x) {
    return x==fa[x]?x:fa[x]=root(fa[x]);
}

bool unite(int x,int y) {
    int rx=root(x),ry=root(y);
    if(rx==ry) return false;
    if(rx<ry) {
        fa[ry]=rx;
        cnt[rx]+=cnt[ry];
    } else {
        fa[rx]=ry;
        cnt[ry]+=cnt[rx];
    }
    return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    M=0;
    for(int i=1; i<=MAXM; i++) {
        fa[i]=i;
        cnt[i]=0;
    }
    int K,x,y;
    for(int i=0; i<N; i++) {
        scanf("%d: %d",&K,&x);
        M=max(M,x);
        for(int j=1; j<K; j++) {
            scanf("%d",&y);
            M=max(M,y);
            unite(x,y);
        }
        cnt[root(x)]++;
    }
    vector<int> v;
    for(int i=1; i<=M; i++) if(fa[i]==i && cnt[i]>0)
            v.push_back(cnt[i]);
    sort(v.rbegin(),v.rend());
    printf("%d\n",v.size());
    for(int i=0; i<v.size(); i++)
        printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    return 0;
}

/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

3
4 3 1
*/
