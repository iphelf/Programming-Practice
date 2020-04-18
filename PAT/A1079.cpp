#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN=1e5;

int N,a[MAXN];
vector<int> child[MAXN];
double R;
double ans;

void dfs(int r,double p) {
    if(child[r].empty()) {
        ans+=a[r]*p;
        return;
    }
    p+=p*R;
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
        if(K==0) scanf("%d",&a[r]);
        else {
            for(int i=0; i<K; i++) {
                scanf("%d",&c);
                child[r].push_back(c);
            }
        }
    }
    ans=0;
    dfs(0,P);
    printf("%.1f\n",round(ans*10)/10);
    return 0;
}

/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

42.4
*/
