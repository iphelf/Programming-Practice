#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long solve(string n,int d){
    long long p=0;
    for(int i=0;i<n.size();i++) if(n[i]-'0'==d){
        p=p*10+d;
    }
    return p;
}

int main(void){
//    freopen("in.txt","r",stdin);
    string A,B;
    int Da,Db;
    while(cin>>A>>Da>>B>>Db){
        long long Pa=solve(A,Da),Pb=solve(B,Db);
        printf("%lld\n",Pa+Pb);
    }
    return 0;
}

/*
3862767 6 13530293 3
3862767 1 13530293 8

399
0
*/

