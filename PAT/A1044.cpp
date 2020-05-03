#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

const int MAXN=1e5;
typedef pair<int,int> pii;

int N,M,sub[MAXN+1];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M)) {
        sub[0]=0;
        for(int i=1; i<=N; i++) {
            scanf("%d",&sub[i]);
            sub[i]+=sub[i-1];
        }
        vector<pii> ans;
        int lost=sub[N]-M;
        for(int l=0; l<=N; l++) {
            int *lb=lower_bound(sub+1,sub+1+N,sub[l]+M);
            int *rb=upper_bound(sub+1,sub+1+N,sub[l]+M);
            if(lb==sub+1+N) continue;
            int tLost=*lb-sub[l]-M;
            if(tLost>lost) continue;
            if(lb==rb) rb=upper_bound(sub+1,sub+1+N,sub[l]+M+tLost);
            if(tLost<lost) {
                ans.clear();
                lost=tLost;
            }
            for(int r=lb-sub; r<rb-sub; r++) ans.push_back({l+1,r});
        }
        for(int i=0; i<ans.size(); i++)
            printf("%d-%d\n",ans[i].first,ans[i].second);
    }
    return 0;
}

/*
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
5 13
2 4 5 7 9

1-5
4-6
7-8
11-11
2-4
4-5
*/
