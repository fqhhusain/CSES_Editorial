#include<bits/stdc++.h>
using namespace std;
 
int ans,n,x;
 
int main(){
    cin>>n>>x;
    int arr[n];
    vector<int> dp(x+1,1e9);
    dp[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<=x)
        dp[arr[i]]=1;
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<n ;j++){
            if(i-arr[j]>=0){
            dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        }
    }
    cout<<(dp[x]==1e9?-1:dp[x])<<endl;
}
