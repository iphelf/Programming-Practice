#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int MAXN=1e5;
pair<string,string> p[MAXN+1];

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    scanf("%d ",&N);
    int cnt=0;
    string low="1814/09/06";
    string high="2014/09/06";
    for(int i=0;i<N;i++){
        cin>>p[cnt].second>>p[cnt].first;
        if(p[cnt].first<low||p[cnt].first>high) continue;
        else cnt++;
    }
    sort(p,p+cnt);
    cout<<cnt;
    if(cnt>0) cout<<' '<<p[0].second<<' '<<p[cnt-1].second;
    cout<<endl;
    return 0;
}

/*
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

3 Tom John
*/

