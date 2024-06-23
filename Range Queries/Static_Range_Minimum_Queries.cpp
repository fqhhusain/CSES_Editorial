#include<utility>
#include<iostream>
#include<cmath>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
 
#define int long long
#define mod 1000000007
#define Log 18
#define maks 200005
 
 
using namespace std;
 
vector<vector<int>> dp(maks,vector<int> (Log));
vector<int> bin(maks);
 
int quer(int x,int y){
    if(x==y){
        return dp[x][0];
    }
    int s=y-x+1;
    int k=bin[s];
    int temp=y-(1<<k);
    int ans=min(dp[x][k],dp[y-(1<<k)+1][k]);
    return ans;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> bil(n);
    bin[1]=0;
    for(int i=2;i<=n;i++){
        bin[i]=bin[i/2]+1;
    }
    for(int i=0;i<n;i++){
        cin>>bil[i];
        dp[i][0]=bil[i];
    }
 
    for(int i=1;i<Log;i++){
        for(int j=0;(j-1+(1<<i))<n;j++){
            dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            int temp=j+1<<(i-1);
            //cout<<j<<" "<<i<<" "<<temp<<" "<<dp[j][i]<<endl;
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<quer(a-1,b-1)<<endl;
    }
}
