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
        if(p>ansP) {
            ansP=p;
            ansN=1;
        } else if(p==ansP) ansN++;
        return;
    }
    p+=p*R;
    for(int c:child[r]) dfs(c,p);
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int r,root=0;
    double P;
    scanf("%d%lf%lf",&N,&P,&R);
    R/=100;
    for(int c=0; c<N; c++) {
        scanf("%d",&r);
        if(r==-1) root=c;
        else child[r].push_back(c);
    }
    ansP=0;
    dfs(root,P);
    printf("%.2f %d\n",round(ansP*1e2)/1e2,ansN);
    return 0;
}

/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6

1.85 2
*/
