#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXL=60;
char week[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(void){
//    freopen("in.txt","r",stdin);
    char DH1[MAXL+1],DH2[MAXL+1];
    char M1[MAXL+1],M2[MAXL+1];
    scanf("%s %s %s %s",DH1,DH2,M1,M2);
    int D,H,M;
    int lenDH=min(strlen(DH1),strlen(DH2));
    int lenM=min(strlen(M1),strlen(M2));
    int i;
    for(i=0;i<lenDH;i++) if(DH1[i]==DH2[i]&&DH1[i]>='A'&&DH1[i]<='G'){
        D=DH1[i]-'A';
        break;
    }
    for(i+=1;i<lenDH;i++) if(DH1[i]==DH2[i]&&((DH1[i]>='0'&&DH1[i]<='9')||(DH1[i]>='A'&&DH1[i]<='N'))){
        if(DH1[i]<='9') H=DH1[i]-'0';
        else H=DH1[i]-'A'+10;
        break;
    }
    for(i=0;i<lenM;i++) if(M1[i]==M2[i]&&((M1[i]>='a'&&M1[i]<='z')||(M1[i]>='A'&&M1[i]<='Z'))){
        M=i;
        break;
    }
    printf("%s %02d:%02d\n",week[D],H,M);
    return 0;
}

/*
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

THU 14:04
*/

