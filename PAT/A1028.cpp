#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=1e5;
struct Student {
    char name[10];
    int id,grade;
};

int N,mode;
Student s[MAXN];

bool cmp(const Student &l,const Student &r) {
    switch (mode) {
    case 1:
        return l.id<r.id;
        break;
    case 2:
        return strcmp(l.name,r.name)==0?l.id<r.id:strcmp(l.name,r.name)<0;
        break;
    case 3:
        return l.grade==r.grade?l.id<r.id:l.grade<r.grade;
        break;
    default:
        break;
    }
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d %d",&N,&mode)) {
        for(int i=0; i<N; i++)
            scanf("%d %s %d",&s[i].id,s[i].name,&s[i].grade);
        sort(s,s+N,cmp);
        for(int i=0; i<N; i++)
            printf("%06d %s %d\n",s[i].id,s[i].name,s[i].grade);
    }
    return 0;
}

/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90

000001 Zoe 60
000007 James 85
000010 Amy 90
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
