#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

const int MAXS=10;

int N,num[MAXS];
char s[MAXS+2];

int main(void) {
//    freopen("in.txt","r",stdin);
    while(~scanf("%s",s)) {
        N=strlen(s);
        for(int i=0; i<N; i++) num[i]=s[i]-'0';
        int pow10=1;
        for(int i=1; i<N; i++) pow10*=10;
        int left=0,right=stoi(s),ans=0;
        for(int i=0; i<N; i++) {
            right-=num[i]*pow10;
            if(num[i]==0) ans+=left*pow10; // X0XX => {0~X-1}1{00~99} => 000~{X-1}99
            else if(num[i]==1) ans+=left*pow10+right+1; // X1XX => {0~X}1{00~99,00~XX} => 000~XXX
            else ans+=(left+1)*pow10; // X2XX => {0~X}1{00~99} => 000~X99
            left=left*10+num[i];
            pow10/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
12

5
*/
