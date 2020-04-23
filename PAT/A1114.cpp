#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

const int MAXN=1e4;
struct Family {
    int id,n;
    double e,a;
};

int N,M,fa[MAXN],cnt[MAXN];
double estate[MAXN],area[MAXN];
bool visited[MAXN];

bool cmp(const Family &l,const Family &r) {
    return l.a==r.a?l.id<r.id:l.a>r.a;
}

int root(int x) {
    return x==fa[x]?x:fa[x]=root(fa[x]);
}

bool unite(int x,int y) {
    int rx=root(x),ry=root(y);
    if(rx==ry) return false;
    if(rx>ry) swap(rx,ry);
    fa[ry]=rx;
    cnt[rx]+=cnt[ry];
    estate[rx]+=estate[ry];
    area[rx]+=area[ry];
    return true;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<MAXN; i++) fa[i]=i;
    memset(cnt,0,sizeof cnt);
    memset(estate,0,sizeof estate);
    memset(area,0,sizeof area);
    memset(visited,false,sizeof visited);
    int id,f,m,k,c;
    double e,a;
    for(int i=0; i<N; i++) {
        scanf("%d%d%d%d",&id,&f,&m,&k);
        visited[id]=true;
        if(~f) {
            unite(id,f);
            visited[f]=true;
        }
        if(~m) {
            unite(id,m);
            visited[m]=true;
        }
        for(int j=0; j<k; j++) {
            scanf("%d",&c);
            unite(id,c);
            visited[c]=true;
        }
        scanf("%lf%lf",&e,&a);
        id=root(id);
        estate[id]+=e;
        area[id]+=a;
    }
    for(int i=0; i<MAXN; i++) if(visited[i]) cnt[root(i)]++;
    vector<Family> v;
    for(int i=0; i<MAXN; i++) if(fa[i]==i && cnt[i]>0)
            v.push_back({i,cnt[i],estate[i]/cnt[i],area[i]/cnt[i]});
    sort(v.begin(),v.end(),cmp);
    printf("%u\n",v.size());
    for(int i=0; i<v.size(); i++)
        printf("%04d %d %.3f %.3f\n",
               v[i].id,v[i].n,
               round(v[i].e*1e3)/1e3,
               round(v[i].a*1e3)/1e3);
    return 0;
}

/*
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100

3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/
