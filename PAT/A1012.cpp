#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int MAXN=2e3;
struct Student {
    int id,score[4],rank[4],best;
};

int N,mode;
Student s[MAXN];
map<int,int> m;

bool cmp(const Student &l,const Student &r) {
    return l.score[mode]>r.score[mode];
}

bool cmpId(const Student &l,const Student &r) {
    return l.id<r.id;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,id;
    char type[5]="ACME";
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++) {
        scanf("%d",&id);
        m[id]=i;
        s[i].id=i;
        s[i].score[0]=0;
        for(int j=1; j<4; j++) {
            scanf("%d",&s[i].score[j]);
            s[i].score[0]+=s[i].score[j];
        }
    }
    for(mode=0; mode<4; mode++) {
        sort(s,s+N,cmp);
        s[0].rank[mode]=1;
        for(int i=1; i<N; i++)
            s[i].rank[mode]=(s[i].score[mode]==s[i-1].score[mode]
                             ?s[i-1].rank[mode]
                             :i+1);
    }
    for(int i=0; i<N; i++)
        s[i].best=min_element(s[i].rank,s[i].rank+4)-s[i].rank;
    sort(s,s+N,cmpId);
    for(int i=0; i<M; i++) {
        scanf("%d",&id);
        if(m.find(id)==m.end()) {
            puts("N/A");
            continue;
        }
        id=m[id];
        printf("%d %c\n",s[id].rank[s[id].best],type[s[id].best]);
    }
    return 0;
}

/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

1 C
1 M
1 E
1 A
3 A
N/A
*/
