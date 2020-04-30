#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXM=1e2,MAXK=3e2,MAXN=MAXM*MAXK;
struct Student {
    int score,group,local,final;
    char *id;
};

int N,lb[MAXM+1];
Student s[MAXN];
char id[MAXN][15];

bool cmp(const Student &l,const Student &r) {
    return l.score==r.score?strcmp(l.id,r.id)<0:l.score>r.score;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,tN,score;
    scanf("%d",&M);
    N=0;
    for(int i=0; i<M; i++) {
        scanf("%d",&tN);
        lb[i]=N;
        for(int j=0; j<tN; j++,N++) {
            scanf(" %s %d",id[N],&s[N].score);
            s[N].id=id[N];
            s[N].group=i+1;
        }
        sort(s+lb[i],s+N,cmp);
        s[lb[i]].local=1;
        for(int j=lb[i]+1; j<N; j++)
            s[j].local=s[j].score==s[j-1].score?s[j-1].local:j-lb[i]+1;
    }
    lb[M]=N;
    printf("%d\n",N);
    sort(s,s+N,cmp);
    s[0].final=1;
    for(int i=1; i<N; i++)
        s[i].final=s[i].score==s[i-1].score?s[i-1].final:i+1;
    for(int i=0; i<N; i++)
        printf("%s %d %d %d\n",s[i].id,s[i].final,s[i].group,s[i].local);
    return 0;
}

/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
