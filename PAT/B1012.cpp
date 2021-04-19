#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    while(~scanf("%d",&N)){
        int t;
        vector<int> v[5];
        for(int i=0;i<N;i++){
            scanf("%d",&t);
            if(t%5==0){if(t%2==0) v[0].push_back(t);}
            else v[t%5].push_back(t);
        }
        if(v[0].empty()) putchar('N');
        else{
            int sum=0;
            for(int i=0;i<v[0].size();i++) if(v[0][i]%2==0)
                sum+=v[0][i];
            printf("%d",sum);
        }
        putchar(' ');
        if(v[1].empty()) putchar('N');
        else{
            int sum=0;
            for(int i=0;i<v[1].size();i++)
                sum+=(i%2==0?1:-1)*v[1][i];
            printf("%d",sum);
        }
        putchar(' ');
        if(v[2].empty()) putchar('N');
        else{
            printf("%d",v[2].size());
        }
        putchar(' ');
        if(v[3].empty()) putchar('N');
        else{
            double sum=0;
            for(int i=0;i<v[3].size();i++) sum+=v[3][i];
            printf("%.1f",sum/v[3].size());
        }
        putchar(' ');
        if(v[4].empty()) putchar('N');
        else{
            int m=v[4][0];
            for(int i=1;i<v[4].size();i++) m=max(m,v[4][i]);
            printf("%d",m);
        }
        putchar('\n');
    }
    return 0;
}

/*
13 1 2 3 4 5 6 7 8 9 10 20 16 18
8 1 2 4 5 6 7 9 16

30 11 2 9.7 9
N 11 2 N 9
*/

