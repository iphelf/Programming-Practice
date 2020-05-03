#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MAXS=10;
struct Integer {
    vector<ll> data;
    const int capacity=1e9;
    Integer &operator =(const Integer &r) {
        data=r.data;
        return *this;
    }
    Integer(const Integer &r) {
        data=r.data;
    }
    Integer(ll n=0) {
        data.push_back(n);
        carry();
    }
    void carry() {
        int up=0;
        for(int i=0; i<data.size(); i++) {
            if(data[i]>=capacity) {
                up=data[i]/capacity;
                data[i]%=capacity;
            } else up=0;
        }
        if(up) data.push_back(up);
    }
    Integer &operator +=(ll x) {
        for(int i=0; i<data.size(); i++) data[i]+=x;
        carry();
        return *this;
    }
    Integer &operator +=(const Integer &x) {
        for(int i=min(x.data.size(),data.size())-1; i>=0; i--)
            data[i]+=x.data[i];
        if(x.data.size()>this->data.size())
            for(int i=this->data.size(); i<x.data.size(); i++)
                this->data.push_back(x.data[i]);
        carry();
    }
    Integer &operator *=(ll x) {
        for(int i=0; i<data.size(); i++)
            data[i]=data[i]*x;
        carry();
        return *this;
    }
    Integer operator *(ll x) {
        Integer ret(*this);
        return ret*=x;
    }
    bool operator ==(const Integer &x) {
        return data==x.data;
    }
    bool operator <(const Integer &x) {
        if(data.size()!=x.data.size()) return data.size()<x.data.size();
        for(int i=data.size()-1; i>=0; i--) if(data[i]!=x.data[i])
                return data[i]<x.data[i];
        return false;
    }
    bool operator >=(const Integer &x) {
        return !(*this<x);
    }
};

char sN1[MAXS+2],sN2[MAXS+2];
Integer N1,N2;

template<typename T>
T findFirst(T l,T r,bool (*ok)(T)) {
    T m;
    while(l<r) {
        m=l+floor((r-l)/2.0);
        if(ok(m)) r=m;
        else l=m+1;
    }
    return r;
}

int toDecimal(char c) {
    return isalpha(c)?c-'a'+10:c-'0';
}

Integer toDecimal(char s[MAXS+2],ll r) {
    Integer d(0),f(1);
    for(int i=strlen(s)-1; i>=0; i--) {
        ll n=toDecimal(s[i]);
        d+=f*n;
        f*=r;
    }
    return d;
}

bool ok(ll r) {
    N2=toDecimal(sN2,r);
    return N2>=N1;
}

int main(void) {
//    freopen("in.txt","r",stdin);
    int tag,radix;
    while(~scanf("%s%s%d%d",sN1,sN2,&tag,&radix)) {
        if(tag==2) swap(sN1,sN2);
        N1=toDecimal(sN1,radix);
        ll l=max(2,toDecimal(*max_element(sN2,sN2+strlen(sN2)))+1);
        ll r=2.1875e9; //hehehehehehehe...
        radix=findFirst(l,r,ok);
        if(toDecimal(sN2,radix)==N1) printf("%d\n",radix);
        else puts("Impossible");
    }
    return 0;
}

/*
6 110 1 10
1 ab 1 2

2
Impossible
*/
