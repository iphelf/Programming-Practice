#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=1e3;
struct Mooncake {
    double amount,price;
};

int N;
double D;
Mooncake m[MAXN];

bool cmp(Mooncake &l,Mooncake &r) {
    return l.price*r.amount>r.price*l.amount;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    scanf("%d%lf",&N,&D);
    for(int i=0; i<N; i++) scanf("%lf",&m[i].amount);
    for(int i=0; i<N; i++) scanf("%lf",&m[i].price);
    sort(m,m+N,cmp);
    double p=0;
    for(int i=0; i<N; i++) {
        if(D<=m[i].amount) {
            p+=m[i].price/m[i].amount*D;
            D=0;
            break;
        }
        p+=m[i].price;
        D-=m[i].amount;
    }
    printf("%.2f\n",round(p*1e2)/1e2);
    return 0;
}

/*
3 200
180 150 100
7.5 7.2 4.5

9.45
*/
