#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN=4e4,MAXM=1e2,MAXK=5;
struct Student {
    int e,i,p[MAXK],id;
};

int N,M,K,quota[MAXM];
Student s[MAXN];
vector<Student *> ac[MAXM];

bool cmpGrade(const Student &l,const Student &r) {
    return l.e+l.i==r.e+r.i ? l.e>r.e : l.e+l.i>r.e+r.i;
}

bool cmpId(const Student *l,const Student *r) {
    return l->id < r->id;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0; i<M; i++) scanf("%d",&quota[i]);
    for(int i=0; i<N; i++) {
        scanf("%d%d",&s[i].e,&s[i].i);
        for(int j=0; j<K; j++) scanf("%d",&s[i].p[j]);
        s[i].id=i;
    }
    sort(s,s+N,cmpGrade);
    int k;
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) {
            k=s[i].p[j];
            if(ac[k].empty()) {
                ac[k].push_back(s+i);
                break;
            }
            Student &last=*ac[k].back();
            if(ac[k].size()<quota[k] || (s[i].e==last.e && s[i].i==last.i)) {
                ac[k].push_back(s+i);
                break;
            }
        }
    }
    for(int i=0; i<M; i++) {
        sort(ac[i].begin(),ac[i].end(),cmpId);
        for(int j=0; j<ac[i].size(); j++)
            printf("%d%c",ac[i][j]->id,j==ac[i].size()-1?'\n':' ');
        if(ac[i].empty()) putchar('\n');
    }
    return 0;
}

/*
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4

0 10
3
5 6 7
2 8

1 4
*/
