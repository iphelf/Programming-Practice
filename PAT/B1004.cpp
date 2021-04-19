#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=100000;

struct Student{
    char name[11];
    char id[11];
    int score;
} s[MAXN];

bool cmp(Student &l,Student &r){return l.score<r.score;}

int main(void) {
//    freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf(" %s %s %d ",s[i].name,s[i].id,&s[i].score);
    sort(s,s+N,cmp);
    printf("%s %s\n%s %s\n",s[N-1].name,s[N-1].id,s[0].name,s[0].id);
    return 0;
}

/*
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

Mike CS991301
Joe Math990112
*/

