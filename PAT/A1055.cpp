#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=1e5,MAXA=2e2,MAXM=1e2;
struct Person {
    char name[10];
    int age,worth;
};

int N;
Person p[MAXN];

bool cmp(const Person &l,const Person &r) {
    if(l.worth!=r.worth) return l.worth>r.worth;
    if(l.age!=r.age) return l.age<r.age;
    return strcmp(l.name,r.name)<0;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int K,M,L,R;
    scanf("%d%d",&N,&K);
    for(int i=0; i<N; i++)
        scanf(" %s %d %d",p[i].name,&p[i].age,&p[i].worth);
    sort(p,p+N,cmp);
    for(int k=1; k<=K; k++) {
        printf("Case #%d:\n",k);
        int cnt=0;
        scanf("%d%d%d",&M,&L,&R);
        for(int i=0; i<N && cnt<M; i++) if(L<=p[i].age && p[i].age<=R) {
                printf("%s %d %d\n",p[i].name,p[i].age,p[i].worth);
                cnt++;
            }
        if(cnt==0) puts("None");
    }
    return 0;
}

/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50

Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/
