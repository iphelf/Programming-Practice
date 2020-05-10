#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=5e1,MAXM=1e4,MAXK=2e3;

int N;
double ans[MAXN+1][MAXN+1];
vector<int> s[MAXN+1];
vector<int> v(MAXM*2);

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    int M,x,K,y;
    for(int i=1; i<=N; i++) {
        scanf("%d",&M);
        for(int j=0; j<M; j++) {
            scanf("%d",&x);
            s[i].push_back(x);
        }
        sort(s[i].begin(),s[i].end());
        s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
        for(int j=1; j<=N; j++) ans[i][j]=-1;
        ans[i][i]=s[i].size();
    }
    scanf("%d",&K);
    vector<int>::iterator it;
    int inter,total;
    for(int k=0; k<K; k++) {
        scanf("%d%d",&x,&y);
        if(ans[x][y]<0) {
            it=set_union(s[x].begin(),s[x].end(),
                         s[y].begin(),s[y].end(),
                         v.begin());
            total=it-v.begin();
            it=set_intersection(s[x].begin(),s[x].end(),
                                s[y].begin(),s[y].end(),
                                v.begin());
            inter=it-v.begin();
            ans[x][y]=ans[y][x]=100.0*inter/total;
        }
        printf("%.1f%%\n",round(ans[x][y]*10)/10);
    }
    return 0;
}

/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3

50.0%
33.3%
*/
