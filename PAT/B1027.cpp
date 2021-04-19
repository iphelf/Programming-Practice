#include<stdio.h>
#include<math.h>
using namespace std;

char ch;

void print(int n,int d){
    for(int i=0;i<d-n;i++) putchar(' ');
    for(int i=0;i<2*n-1;i++) putchar(ch);
    putchar('\n');
}

int main(void){
//    freopen("in.txt","r",stdin);
    int N,d;
    scanf("%d %c ",&N,&ch);
    d=floor(sqrt((N+1.0)/2));
    for(int i=d;i>=1;i--) print(i,d);
    for(int i=2;i<=d;i++) print(i,d);
    printf("%d\n",N-(2*d*d-1));
    return 0;
}

/*
19 *

*****
 ***
  *
 ***
*****
2
*/

