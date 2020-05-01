#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>

using namespace std;

const int MAXN=1e5;
struct School {
    int id,n;
    double tws;
};

int N,M;
School s[MAXN];
map<string,int> sid;
string sname[MAXN];

bool cmp(School &l,School &r) {
    if(l.tws!=r.tws) return l.tws>r.tws;
    if(l.n!=r.n) return l.n<r.n;
    return sname[l.id]<sname[r.id];
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int score,schId;
    string stdName,schName;
    cin>>N;
    M=0;
    for(int i=0; i<N; i++) {
        cin>>stdName>>score>>schName;
        transform(schName.begin(),schName.end(),schName.begin(),::tolower);
        if(sid.find(schName)==sid.end()) {
            sid[schName]=M;
            sname[M]=schName;
            s[M].id=M;
            s[M].n=0;
            M++;
        }
        schId=sid[schName];
        s[schId].n++;
        if(stdName[0]=='A') s[schId].tws+=score;
        else if(stdName[0]=='B') s[schId].tws+=score/1.5;
        else s[schId].tws+=score*1.5;
    }
    for(int i=0; i<M; i++) s[i].tws=floor(s[i].tws);
    cout<<M<<endl;
    sort(s,s+M,cmp);
    int rank=1;
    for(int i=0; i<M; i++) {
        if(i>0 && s[i].tws!=s[i-1].tws) rank=i+1;
        cout<<rank<<' '
            <<sname[s[i].id]<<' '
            <<int(s[i].tws)<<' '
            <<s[i].n<<endl;
    }
    return 0;
}

/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/
