#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
 
using namespace std;
 
int kali(int x,int y){
    int ans=1;
    if(!y){
        return ans;
    }
    while(y>1){
        if(y%2==1){
            y-=1;
            ans=(ans*x) % mod;
        }
        x=(x*x) % mod;
        y/=2;
    }
    ans=(ans*x)% mod;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    while(n){
    int a,b;
    cin>>a>>b;
    int hasil=kali(a,b);
    cout<<hasil<<endl;
    n--;
    }
}
