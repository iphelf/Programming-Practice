#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

const int MAXN=4e4;

int N,K;
map<string,vector<int>> s;

int main(void) {
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    int i,n;
    string name;
    for(int k=0; k<K; k++) {
        cin>>i>>n;
        for(int j=0; j<n; j++) {
            cin>>name;
            s[name].push_back(i);
        }
    }
    for(int i=0; i<N; i++) {
        cin>>name;
        vector<int> &v=s[name];
        cout<<name<<' '<<v.size();
        sort(v.begin(),v.end());
        for(int j=0; j<v.size(); j++)
            cout<<' '<<v[j];
        cout<<'\n';
    }
    return 0;
}

/*
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9

ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/
