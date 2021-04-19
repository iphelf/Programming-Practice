#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=1e3;

struct Cake{double p,n;} c[MAXN+1];

bool cmp(Cake &l,Cake &r){return l.p>r.p;}

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    double D;
    scanf("%d%lf",&N,&D);
    for(int i=0;i<N;i++) scanf("%lf",&c[i].n);
    for(int i=0;i<N;i++){
        scanf("%lf",&c[i].p);
        c[i].p/=c[i].n;
    }
    sort(c,c+N,cmp);
    double profit=0,amount=D;
    for(int i=0;i<N;i++){
        if(amount>=c[i].n){
            profit+=c[i].p*c[i].n;
            amount-=c[i].n;
        }
        else{
            profit+=c[i].p*amount;
            break;
        }
    }
    printf("%.2f\n",profit);
    return 0;
}

/*
3 20
18 15 10
75 72 45

94.50
*/

