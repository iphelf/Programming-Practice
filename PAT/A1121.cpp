#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

const int MAXN=5e4,MAXM=1e4;
typedef pair<int,int> pii;

int N,M;
vector<pii> couple;
set<int> atparty;

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    couple.resize(N*2);
    for(int i=0; i<N; i++)
        scanf("%d%d",&couple[i].first,&couple[i].second);
    scanf("%d",&M);
    for(int i=0,id; i<M; i++) {
        scanf("%d",&id);
        atparty.insert(id);
    }
    for(int i=0; i<N; i++) {
        bool foundFirst=atparty.find(couple[i].first)!=atparty.end();
        bool foundSecond=atparty.find(couple[i].second)!=atparty.end();
        if(!(foundFirst&&foundSecond)) continue;
        atparty.erase(couple[i].first);
        atparty.erase(couple[i].second);
    }
    printf("%d\n",atparty.size());
    set<int>::iterator it=atparty.begin();
    while(!atparty.empty()) {
        printf("%05d",*it);
        it++;
        if(it==atparty.end()) {
            putchar('\n');
            break;
        }
        putchar(' ');
    }
    return 0;
}

/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

5
10000 23333 44444 55555 88888
*/
