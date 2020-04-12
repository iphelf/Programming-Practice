#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXS=1e3;

int N;
char s[MAXS+1];
bool dp[MAXS][MAXS];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(cin.getline(s,MAXS+10)) {
        N=strlen(s);
        int ans=1;
        for(int l=0,r=0; r<N; l++,r++) dp[l][r]=true;
        for(int l=0,r=l+1; r<N; l++,r++) {
            if(s[l]==s[r]) {
                dp[l][r]=true;
                ans=2;
            } else dp[l][r]=false;
        }
        for(int len=3; len<=N; len++) {
            for(int l=0,r=l+len-1; r<N; l++,r++) {
                if(s[l]==s[r] && dp[l+1][r-1]) {
                    dp[l][r]=true;
                    ans=len;
                } else dp[l][r]=false;
            }
            if(ans<len-1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
Is PAT&TAP symmetric?

11
*/
