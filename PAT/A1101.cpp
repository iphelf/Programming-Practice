#include<cstdio>
#include<vector>

using namespace std;

const int MAXN=1e5;

int N,a[MAXN],lMax[MAXN],rMin[MAXN];

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&a[i]);
    lMax[0]=a[0];
    for(int i=1; i<N; i++) lMax[i]=max(lMax[i-1],a[i]);
    rMin[N-1]=a[N-1];
    for(int i=N-2; i>=0; i--) rMin[i]=min(rMin[i+1],a[i]);
    int ans=0;
    vector<int> cand;
    for(int i=0; i<N; i++) if(lMax[i]<=a[i] && a[i]<=rMin[i]) {
            ans++;
            cand.push_back(a[i]);
        }
    printf("%d\n",ans);
    for(int i=0; i<cand.size(); i++)
        printf("%d%c",cand[i],i==cand.size()-1?'\n':' ');
    if(cand.empty()) putchar('\n');
    return 0;
}

/*
5
1 3 2 4 5

3
1 4 5
*/
