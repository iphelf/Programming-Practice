#include<stdio.h>
#include<math.h>
using namespace std;

int main(void){
//    freopen("in.txt","r",stdin);
    int before,after;
    scanf("%d%d",&before,&after);
    int second=round((after-before)/100.0);
    int minute=second/60;
    second%=60;
    int hour=minute/60;
    minute%=60;
    printf("%02d:%02d:%02d\n",hour,minute,second);
    return 0;
}

/*
123 4577973

12:42:59
*/

