#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

const int MAXN=4e4,MAXK=2.5e3;

int N,K;
vector<int> s[MAXK+1];
string name[MAXN];

bool cmp(int l,int r) {
    return name[l]<name[r];
}

int main(void) {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    int n,k;
    for(int i=0; i<N; i++) {
        cin>>name[i]>>n;
        for(int j=0; j<n; j++) {
            cin>>k;
            s[k].push_back(i);
        }
    }
    for(int k=1; k<=K; k++) {
        cout<<k<<' '<<s[k].size()<<'\n';
        sort(s[k].begin(),s[k].end(),cmp);
        for(int i=0; i<s[k].size(); i++)
            cout<<name[s[k][i]]<<'\n';
    }
    return 0;
}

/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
*/
