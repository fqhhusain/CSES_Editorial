#include<bits/stdc++.h>
#define int long long
#define mod (1000000007)
 
using namespace std;
 
int dp[1001][1<<11];
 
void generate(int mask,int i,int next,int n,vector<int>& listbit){
    if(i==n+1){
        listbit.push_back(next);
        return;
    }
    if(mask&(1<<i)){
        generate(mask,i+1,next,n,listbit);
    }
    if((mask&(1<<i))==0){
        generate(mask,i+1,next+(1<<i),n,listbit);
    }
    if(i!=n){
        if((mask&(1<<i))==0){
            if((mask&(1<<i+1))==0){
        generate(mask,i+2,next,n,listbit);
    }
    }
    }
}
 
int f(int n,int m,int bit,int cur)
{
    if(cur==m+1){
        if(bit==0){
            return 1;
        }else return 0;
    }
    if(dp[cur][bit]!=-1){
        return dp[cur][bit];
    }
    
    int ans=0;
    vector<int> listbit;
    generate(bit,1,0,n,listbit);
    for(auto v : listbit){
        ans=(ans+f(n,m,v,cur+1))%mod;
    }
    return dp[cur][bit]=ans;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    int ans=f(n,m,0,1);
    cout<<ans<<endl;
}
