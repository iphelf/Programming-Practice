#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(string &l,string &r) {
    return l+r<r+l;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int N;
    cin>>N;
    vector<string> segs(N);
    for(int i=0; i<N; i++) cin>>segs[i];
    sort(segs.begin(),segs.end(),cmp);
    ostringstream oss;
    for(int i=0; i<N; i++) oss<<segs[i];
    string output=oss.str();
    for(size_t i=0; i<output.size(); i++) if(output[i]!='0') {
            output=output.substr(i);
            break;
        }
    if(output[0]=='0') output="0";
    cout<<output<<'\n';
    return 0;
}

/*
5 32 321 3214 0229 87

22932132143287
*/
