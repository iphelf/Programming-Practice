#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string A;
int B;
string Q;
int R;

void solve(){
    int i=0;
    R=0;
    Q="";
    while(i<A.size()){
        R=R*10+A[i]-'0';
        Q+=(R/B)+'0';
        R=R%B;
        i++;
    }
    if(Q[0]=='0' && Q.size()>1) Q=Q.substr(1);
}

int main(void){
//    freopen("in.txt","r",stdin);
    while(cin>>A>>B){
        solve();
        cout<<Q<<' '<<R<<endl;
    }
    return 0;
}

/*
123456789050987654321 7

17636684150141093474 3
*/

