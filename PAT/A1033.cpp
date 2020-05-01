#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN=500,MAXD=3e4,INF=0x3f3f3f3f;
struct GasStation {
    double price;
    int pos;
};

int D,N,C;
double avgD;
GasStation gas[MAXN+1];

bool cmp(GasStation &l,GasStation &r) {
    return l.pos==r.pos ? l.price<r.price : l.pos<r.pos;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%lf%d",&C,&D,&avgD,&N)) {
        for(int i=0; i<N; i++) scanf("%lf%d",&gas[i].price,&gas[i].pos);
        gas[N].pos=D;
        sort(gas,gas+N+1,cmp);
        if(gas[0].pos>0) {
            puts("The maximum travel distance = 0.00");
            continue;
        }
        int from=0,to;
        double cost=0,dist=0,d,gap=C*avgD,stock=0;
        bool ok=true;
        while(dist<D) {
            if(gas[from+1].pos-gas[from].pos>gap) {
                dist=gas[from].pos+gap;
                ok=false;
                break;
            }
            to=from+1;
            for(int i=from+1; i<=N && gas[i].pos-gas[from].pos<=gap; i++) {
                if(gas[i].price<gas[from].price) {
                    to=i;
                    break;
                }
                if(gas[i].price<gas[to].price) to=i;
            }
            d=gas[to].pos-gas[from].pos;
            if(gas[to].price<gas[from].price) {
                cost+=(d/avgD-stock)*gas[from].price;
                stock=0;
            } else {
                cost+=(C-stock)*gas[from].price;
                stock=C-d/avgD;
            }
            dist=gas[to].pos;
            from=to;
        }
        if(!ok)
            printf("The maximum travel distance = %.2f\n",
                   round(dist*1e2)/1e2);
        else
            printf("%.2f\n",
                   round(cost*1e2)/1e2);
    }
    return 0;
}

/*
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
50 1300 12 2
7.10 0
7.00 600

749.17
The maximum travel distance = 1200.00
*/
