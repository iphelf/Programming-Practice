#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN=1e5;

int N;
vector<int> child[MAXN];
double R;
double ansP;
int ansN;

void dfs(int r,double p) {
    if(child[r].empty()) {
        if(p<ansP) {
            ansP=p;
            ansN=1;
        } else if(p==ansP) ansN++;
        return;
    }
    p+=p*R;
    if(p>ansP) return;
    for(int c:child[r]) dfs(c,p);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int K,c;
    double P;
    scanf("%d%lf%lf",&N,&P,&R);
    R/=100;
    for(int r=0; r<N; r++) {
        scanf("%d",&K);
        if(K==0) continue;
        for(int i=0; i<K; i++) {
            scanf("%d",&c);
            child[r].push_back(c);
        }
    }
    ansP=1e10;
    dfs(0,P);
    printf("%.4f %d\n",round(ansP*1e4)/1e4,ansN);
    return 0;
}

/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0

1.8362 2
*/
