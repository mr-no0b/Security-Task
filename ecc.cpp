#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll base,ll exp,ll mod){
    if(exp==0)return 1;
    ll x=power(base,exp/2,mod);
    x=x*x%mod;
    if(exp%2)x=x*base%mod;
    return x;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll extGcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;return a;
    }
    ll x1,y1;
    ll g=extGcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
ll modInv(ll a,ll b){
    ll x,y,g=extGcd(a,b,x,y);
    return (x%b+b)%b;
}

struct Point{
    ll x,y;
    Point(ll a,ll b){
        x=a;y=b;
    }
    Point pointDouble(ll a,ll mod){
        if(y==0)return Point(10000,10000);
        ll m=(3*x*x+a)%mod;m=m*modInv(2*y%mod,mod)%mod;
        ll x1=((m*m-2*x)%mod+mod)%mod;
        ll y1=((m*(((x-x1)%mod+mod)%mod)%mod)-y)%mod;
        y1=(y1+mod)%mod;
        return Point(x1,y1);
    }
    Point pointAddition(Point p, ll a, ll mod){
        if(x==10000&&y==10000)return p;
        if(p.x==10000&&p.y==10000)return Point(x,y);
        if(x==p.x&&y==p.y)return pointDouble(a,mod);
        if(x==p.x&&(y+p.y)%mod==0)return Point(10000,10000);
        ll m=(p.y-y)%mod;m=(m+mod)%mod;
        m=m*modInv(((p.x-x)%mod+mod)%mod,mod)%mod;
        ll x1=((m*m-x-p.x)%mod+mod)%mod;
        ll y1=((m*(((x-x1)%mod+mod)%mod)%mod)-y)%mod;
        y1=(y1+mod)%mod;
        return Point(x1,y1);
    }
    Point multiply(ll mul,ll mod,ll a){
        if(mul==0)return Point(10000,10000);
        if(mul==1)return Point(x,y);
        Point half=multiply(mul/2,mod,a);
        half=half.pointDouble(a,mod);
        if(mul%2)half=half.pointAddition(Point(x,y),a,mod);
        return half;
    }
    Point inv(ll mod){
        return Point(x,(mod-y)%mod);
    }
};

int main(){
    //4a^3+27b^2 modP!=0
    
    ll a=7,b=24,p=97;
    Point G(0,11);
    ll e=5; Point d=G.multiply(e,p,a);
    ll k=2;
    cout<<"Enter messages (m1,m2): ";
    ll m1,m2;cin>>m1>>m2;
    Point m(m1,m2);
    //encryptioin
    Point c1=G.multiply(k,p,a);
    Point c2=m.pointAddition(d.multiply(k,p,a),a,p);
    cout<<"C1 : "<<c1.x<<" "<<c1.y<<endl;
    cout<<"C2 : "<<c2.x<<" "<<c2.y<<endl;
    //decryption
    Point decryp=c2.pointAddition((c1.multiply(e,p,a)).inv(p),a,p);
    cout<<"Message "<<decryp.x<<" "<<decryp.y<<endl;
}