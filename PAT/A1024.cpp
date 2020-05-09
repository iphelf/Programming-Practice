#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool isPalindrome(string s) {
    int i=0,j=s.size()-1;
    while(i<j) {
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}

string add(string l,string r) {
    int carry=0,n=max(l.size(),r.size()),d[n+1];
    int i=l.size()-1,j=r.size()-1,k=0;
    while(i>=0 || j>=0) {
        d[k]=(i<0?0:l[i]-'0')+(j<0?0:r[j]-'0');
        k++,i--,j--;
    }
    for(int i=0; i<n; i++) {
        d[i]+=carry;
        carry=d[i]/10;
        d[i]%=10;
    }
    if(carry>0) d[n++]=carry;
    string ans(n,'0');
    for(int i=0; i<n; i++) ans[i]='0'+d[n-1-i];
    return ans;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int k,K;
    string N,rN;
    while(cin>>N>>K) {
        for(k=0; k<K; k++) {
            if(isPalindrome(N)) break;
            rN=N;
            reverse(rN.begin(),rN.end());
            N=add(N,rN);
        }
        cout<<N<<'\n'<<k<<'\n';
    }
    return 0;
}

/*
67 3
69 3

484
2
1353
3
*/
