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
int main(){
    cout<<"Enter two primes: ";
    ll p,q;cin>>p>>q;
    ll N=p*q,phi=(p-1)*(q-1);
    ll e;
    for(ll i=2;i<phi;i++){
        if(gcd(i,phi)==1){e=i;break;}
    }
    cout<<"Public Key: "<<e<<endl;
    ll d=modInv(e,phi);
    cout<<"Private Key: "<<d<<endl;
    cout<<"Enter Message1: ";
    ll m1;cin>>m1;
    cout<<"Enter Message2: ";
    ll m2;cin>>m2;


    
    cout<<"Encryption(M1*M2)\n";
    //encryption
    ll cipher=power((m1*m2)%N,e,N);cout<<"Cipher: "<<cipher<<endl;
    //sign
    ll sign=power(cipher,d,N);cout<<"Sign: "<<sign<<endl;
    //verify
    ll verify=power(sign,e,N);cout<<"Verify: "<<verify<<endl;
    //decryption
    ll decryp=power(verify,d,N);cout<<"Decryption: "<<decryp<<endl;



    cout<<"Encryption(M1)*Encryption(M2)\n";
    //encryption
    cipher=(power(m1,e,N)*power(m2,e,N))%N;cout<<"Cipher: "<<cipher<<endl;
    //sign
    sign=power(cipher,d,N);cout<<"Sign: "<<sign<<endl;
    //verify
    verify=power(sign,e,N);cout<<"Verify: "<<verify<<endl;
    //decryption
    decryp=power(verify,d,N);cout<<"Decryption: "<<decryp<<endl;


}