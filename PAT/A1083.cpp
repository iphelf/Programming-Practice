#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN=1e7;
struct Student {
    char name[12],id[12];
    int grade;
};

int N;
Student s[MAXN];

bool cmp(const Student &l,const Student &r) {
    return l.grade>r.grade;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int L,R;
    while(~scanf("%d",&N)) {
        for(int i=0; i<N; i++) scanf(" %s %s %d",s[i].name,s[i].id,&s[i].grade);
        scanf("%d%d",&L,&R);
        sort(s,s+N,cmp);
        int l=0,r=0;
        while(l<N && s[l].grade>R) l++;
        while(r<N && s[r].grade>=L) r++;
        if(r<=l || l==N || r==0) puts("NONE");
        else for(int i=l; i<r; i++) printf("%s %s\n",s[i].name,s[i].id);
    }
    return 0;
}

/*
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
2
Jean AA980920 60
Ann CS01 80
90 95

Mike CS991301
Mary EE990830
Joe Math990112
NONE
*/
