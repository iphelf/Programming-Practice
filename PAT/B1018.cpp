#include<stdio.h>
#include<string.h>
using namespace std;

int toi(char c){
    if(c=='B') return 0;
    else if(c=='C') return 1;
    else return 2;
}

char toc(int n){
    if(n==0) return 'B';
    else if(n==1) return 'C';
    else return 'J';
}

bool judge(int a,int b){
    if((a+1)%3==b) return true;
    else return false;
}

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    char c[2];
    int cnt[2][3];
    int sum[2][3];
    memset(cnt,0,sizeof cnt);
    memset(sum,0,sizeof sum);
    for(int i=0;i<N;i++){
        scanf(" %c %c ",&c[0],&c[1]);
        int a=toi(c[0]);
        int b=toi(c[1]);
        if(judge(a,b)){
            cnt[0][a]++;
            sum[0][0]++;
            sum[1][2]++;
        }
        else if(judge(b,a)){
            cnt[1][b]++;
            sum[0][2]++;
            sum[1][0]++;
        }
        else{
            sum[0][1]++;
            sum[1][1]++;
        }
    }
    for(int i=0;i<2;i++)
        printf("%d %d %d\n",sum[i][0],sum[i][1],sum[i][2]);
    int iMax=0;
    for(int i=1;i<3;i++) if(cnt[0][i]>cnt[0][iMax]) iMax=i;
    printf("%c ",toc(iMax));
    iMax=0;
    for(int i=1;i<3;i++) if(cnt[1][i]>cnt[1][iMax]) iMax=i;
    printf("%c\n",toc(iMax));
    return 0;
}

/*
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

5 3 2
2 3 5
B B
*/

