#include<stdio.h>
#include<string.h>
using namespace std;

const int MAXL=1e5;
char L[MAXL+2],R[MAXL+2];
char s[MAXL+2];

int main(void){
//    freopen("in.txt","r",stdin);
    char opL,opR;
    int p;
    while(~scanf(" %c%[0-9].%[0-9]E%c%d ",&opL,L,R,&opR,&p)){
        memcpy(s,L,strlen(L)*sizeof(char));
        memcpy(s+strlen(L),R,strlen(R)*sizeof(char));
        int len=strlen(L)+strlen(R);
        s[len]='\0';
        int dp=strlen(L);
        if(opL=='-') putchar('-');
        if(opR=='-') dp-=p;
        else dp+=p;
        if(dp<=0){
            printf("0.");
            for(int i=0;i<-dp;i++) putchar('0');
            puts(s);
        }
        else if(dp<len){
            for(int i=0;i<dp;i++) putchar(s[i]);
            putchar('.');
            for(int i=dp;i<len;i++) putchar(s[i]);
        }
        else{
            printf("%s",s);
            for(int i=len;i<dp;i++) putchar('0');
        }
    }
    return 0;
}

/*
+1.23400E-03
-1.2E+10

0.00123400
-12000000000
*/

