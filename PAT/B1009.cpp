#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(void) {
//    freopen("in.txt","r",stdin);
    vector<string> vs;
    string raw;
    while(cin>>raw)
        vs.push_back(raw);
    reverse(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++)
        printf("%s%c",vs[i].data(),i==vs.size()-1?'\n':' ');
    return 0;
}

/*
Hello World Here I Come

Come I Here World Hello
*/

