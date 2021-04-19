#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1e5,MAXL=8;
int N,H,L;
struct Student{
    string id;
    int d,c;
};
bool cmp(Student &l,Student &r){
    int ls=l.d+l.c,rs=r.d+r.c;
    if(ls==rs){
        if(l.d==r.d) return l.id<r.id;
        else return l.d>r.d;
    }
    else return ls>rs;
}

int main(void){
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&L,&H);
    vector<Student> v[4];
    string id;
    int d,c;
    for(int i=0;i<N;i++){
        cin>>id>>d>>c;
        Student ts={id,d,c};
        if(d>=H&&c>=H) v[0].push_back(ts);
        else if(d>=H&&H>c&&c>=L) v[1].push_back(ts);
        else if(H>d && d>=c && c>=L) v[2].push_back(ts);
        else if(d>=L&&c>=L) v[3].push_back(ts);
    }
    int cnt=0;
    for(int i=0;i<4;i++){
        sort(v[i].begin(),v[i].end(),cmp);
        cnt+=v[i].size();
    }
    cout<<cnt<<endl;
    for(int i=0;i<4;i++) for(int j=0;j<v[i].size();j++) cout<<v[i][j].id<<' '<<v[i][j].d<<' '<<v[i][j].c<<endl;
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

