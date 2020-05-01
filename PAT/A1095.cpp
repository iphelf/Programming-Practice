#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

const int MAXN=1e4,MAXM=MAXN,MAXT=24*60*60;
struct Record {
    int i,t,d; //d=1 for in; d=0 for out
};
struct Car {
    int stay,in,id;
};

int N,M,delta[MAXT],cnt[MAXT];
Record r[MAXN];
Car c[MAXM];
map<string,int> id;
char plate[MAXN][10];

int toSecond(int h,int m,int s) {
    return h*3600+m*60+s;
}

void toHMS(int second,int &h,int &m,int &s) {
    h=second/3600;
    second%=3600;
    m=second/60;
    second%=60;
    s=second;
}

bool cmpR(Record &l,Record &r) {
    return l.t<r.t;
}

bool cmpC(Car &l,Car &r) {
    return l.stay==r.stay ? strcmp(plate[l.id],plate[r.id])<0 : l.stay>r.stay;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int K,h,m,s;
    char dir[5];
    scanf("%d%d",&N,&K);
    M=0;
    for(int i=0; i<N; i++) {
        scanf(" %s %d:%d:%d %s",plate[M],&h,&m,&s,dir);
        if(id.find(string(plate[M]))!=id.end())
            r[i].i=id[string(plate[M])];
        else {
            r[i].i=M;
            id[string(plate[M])]=M;
            M++;
        }
        r[i].t=toSecond(h,m,s);
        r[i].d=dir[0]=='i'?1:0;
    }
    sort(r,r+N,cmpR);
    for(int i=0; i<M; i++) {
        c[i].stay=0;
        c[i].in=-1;
        c[i].id=i;
    }
    for(int i=0; i<N; i++) {
        int id=r[i].i;
        if(r[i].d==1) { // in
            if(c[id].in==-1) { // first in
                c[id].in=r[i].t;
                delta[r[i].t]++;
            } else { // repeating in
                delta[c[id].in]--;
                c[id].in=r[i].t;
                delta[r[i].t]++;
            }
        } else { // out
            if(c[id].in==-1) { // no paired in
                continue;
            } else { // well paired
                c[id].stay+=r[i].t-c[id].in;
                c[id].in=-1;
                delta[r[i].t]--;
            }
        }
    }
    for(int i=0; i<M; i++) if(c[i].in!=-1) delta[c[i].in]--;
    cnt[0]=delta[0];
    for(int i=1; i<MAXT; i++) cnt[i]=cnt[i-1]+delta[i];
    for(int k=0; k<K; k++) {
        scanf("%d:%d:%d",&h,&m,&s);
        printf("%d\n",cnt[toSecond(h,m,s)]);
    }
    sort(c,c+M,cmpC);
    printf("%s",plate[c[0].id]);
    for(int i=1; i<M; i++) {
        if(c[i].stay!=c[i-1].stay) break;
        printf(" %s",plate[c[i].id]);
    }
    toHMS(c[0].stay,h,m,s);
    printf(" %02d:%02d:%02d\n",h,m,s);
    return 0;
}

/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00

1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/
