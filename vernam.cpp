#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string char2binary(char c){
    string ans;ll x=c,ctr=8;
    while(ctr--){
        ans.push_back((x%2)+'0');
        x/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string string2binary(string s){
    string ans;
    for(char c:s){
        ans+=char2binary(c);
    }
    return ans;
}
string binary2string(string s){
    string ans;
    for(int i=0;i<s.size();i+=8){
        int x=0,p=128;
        for(int j=i;j<i+8;j++){
            x+=(s[j]-'0')*p;p/=2;
        }
        ans.push_back((char)x);
    }
    return ans;
}

string num2string(ll x,int sz){
    string ans;
    while(sz--){
        ans.push_back((x%2)+'0');
        x/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string Xor(string a, string b){
    string ans;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])ans.push_back('0');
        else ans.push_back('1');
    }
    return ans;
}
int main(){
    cout<<"Enter the message: ";
    string m;cin>>m;
    string mbin=string2binary(m);
    cout<<mbin<<endl;
    srand(time(0));
    string keybin;
    for(ll i=0;i<m.size();i++){
        ll x=rand()%256;
        keybin+=num2string(x,8);
    }
    cout<<"Key is: \n"<<keybin<<endl;
    string cipher=Xor(mbin,keybin);
    cout<<"Cipher is: \n"<<cipher<<endl;
    string decryp=binary2string(Xor(cipher,keybin));
    cout<<"Decryption: "<<decryp<<endl;
}