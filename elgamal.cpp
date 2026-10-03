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
ll primitive(ll p){
    for(ll i=2;i<p;i++){
        set<ll>st;
        ll x=1;
        for(ll j=1;j<=p-1;j++){
            x=(x*i)%p;
            st.insert(x);
        }
        if(st.size()==p-1)return i;
    }
    return -1;
}
int main(){
    ll p=97,alpha=primitive(p),e=14;
    ll d=power(alpha,e,p);
    cout<<"Public: "<<d<<endl;
    cout<<"Private: "<<e<<endl;
    cout<<"Enter message: ";
    ll m;cin>>m;
    //Encryption
    ll k1=7;
    ll c1=power(alpha,k1,p);
    ll c2=m*power(d,k1,p)%p;
    cout<<"Cipher: "<<c1<<" , "<<c2<<endl;
    //Sign
    ll k2=13;
    ll y1=power(alpha,k2,p);
    ll y2=(((m-e*y1)%(p-1)+p-1)%(p-1))*modInv(k2,p-1)%(p-1);
    cout<<"Sign: "<<y1<<" , "<<y2<<endl;
    //verify
    ll left=power(alpha,m,p);
    ll right=power(y1,y2,p)*power(d,y1,p)%p;
    if(left==right)cout<<"Verified"<<endl;
    else cout<<"Not Verified"<<endl;
    //decryption
    ll decryp=modInv(power(c1,e,p),p)*c2%p;
    cout<<"Decryption: "<<decryp<<endl;
}