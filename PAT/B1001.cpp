#include <iostream>

using namespace std;

int main(void){
//    freopen("in.txt","r",stdin);
    int N;
    while(~scanf("%d",&N)){
        int cnt=0;
        while(N>1){
            cnt++;
            if(N&1) N=(N-1)/2*3+2;
            else N=N/2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

/*
3

5
*/
