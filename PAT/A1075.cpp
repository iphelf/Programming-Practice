#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=1e4,MAXK=5;
struct User {
    bool valid,submitted[MAXK];
    int id,score[MAXK],tot,ac;
};

int N,K,p[MAXK];
User user[MAXN];

bool cmp(const User &l,const User &r) {
    if(l.tot!=r.tot) return l.tot>r.tot;
    if(l.ac!=r.ac) return l.ac>r.ac;
    return l.id<r.id;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int M,uid,pid,score;
    scanf("%d%d%d",&N,&K,&M);
    for(int i=0; i<K; i++) scanf("%d",&p[i]);
    for(int i=0; i<N; i++) {
        memset(user[i].score,-1,sizeof user[i].score);
        memset(user[i].submitted,false,sizeof user[i].submitted);
        user[i].tot=0;
        user[i].ac=0;
        user[i].id=i+1;
        user[i].valid=false;
    }
    for(int i=0; i<M; i++) {
        scanf("%d%d%d",&uid,&pid,&score);
        uid--;
        User &u=user[uid];
        pid--;
        u.submitted[pid]=true;
        if(score>u.score[pid]) {
            u.tot-=max(0,u.score[pid]);
            u.tot+=score;
            u.score[pid]=score;
            if(score==p[pid]) u.ac++;
            u.valid=true;
        }
    }
    sort(user,user+N,cmp);
    int rank,cnt=0;
    for(int i=0; i<N; i++) {
        if(!user[i].valid) continue;
        else cnt++;
        if(i==0 || user[i].tot!=user[i-1].tot) rank=cnt;
        printf("%d %05d %d",rank,user[i].id,user[i].tot);
        for(int j=0; j<K; j++) {
            if(~user[i].score[j]) printf(" %d",user[i].score[j]);
            else if(user[i].submitted[j]) printf(" 0");
            else printf(" -");
        }
        putchar('\n');
    }
    return 0;
}

/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0

1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/
