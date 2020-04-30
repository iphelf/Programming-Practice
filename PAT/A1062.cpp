#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=1e5;
struct Person {
    int v,t,i;
};

int N,L,H;
Person p[MAXN];
vector<Person *> sage,nobleman,foolman,rest;

bool cmp(const Person *l,const Person *r) {
    if(l->v+l->t != r->v+r->t) return l->v+l->t > r->v+r->t;
    if(l->v != r->v) return l->v > r->v;
    return l->i < r->i;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&L,&H);
    int cnt=0;
    for(int i=0; i<N; i++) {
        scanf("%d%d%d",&p[i].i,&p[i].v,&p[i].t);
        if(p[i].v<L || p[i].t<L) continue;
        cnt++;
        if(p[i].v>=H && p[i].t>=H) sage.push_back(&p[i]);
        else if(p[i].v>=H && p[i].t>=L) nobleman.push_back(&p[i]);
        else if(p[i].v>=p[i].t) foolman.push_back(&p[i]);
        else rest.push_back(&p[i]);
    }
    printf("%d\n",cnt);
    sort(sage.begin(),sage.end(),cmp);
    for(int i=0; i<sage.size(); i++)
        printf("%08d %d %d\n",sage[i]->i,sage[i]->v,sage[i]->t);
    sort(nobleman.begin(),nobleman.end(),cmp);
    for(int i=0; i<nobleman.size(); i++)
        printf("%08d %d %d\n",nobleman[i]->i,nobleman[i]->v,nobleman[i]->t);
    sort(foolman.begin(),foolman.end(),cmp);
    for(int i=0; i<foolman.size(); i++)
        printf("%08d %d %d\n",foolman[i]->i,foolman[i]->v,foolman[i]->t);
    sort(rest.begin(),rest.end(),cmp);
    for(int i=0; i<rest.size(); i++)
        printf("%08d %d %d\n",rest[i]->i,rest[i]->v,rest[i]->t);
    return 0;
}

/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
