#include<utility>
#include<iostream>
#include<cmath>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
 
#define int long long
#define mod 1000000007
 
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> bil(n+1);
    for(int i=1;i<=n;i++){
        cin>>bil[i];
        if(i!=1){
            bil[i]+=bil[i-1];
        }
    }
    for(int i=0;i<q;i++){
        int a,b,ans;
        cin>>a>>b;
        ans=bil[b];
        if(a!=1){
            ans-=bil[a-1];
        }
        cout<<ans<<endl;
    }
    
}
