#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n;
 
vector<int> bil;
 
int fungsi(int idx,int sum){
    if(idx==n){
        return abs(sum);
    }
    int temp=fungsi(idx+1,sum-bil[idx]);
    int ans=min(temp,fungsi(idx+1,sum+bil[idx]));
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    bil.resize(n);
    for(int i=0;i<n;i++){
        cin>>bil[i];
    }
    int ans=fungsi(0,0);
    cout<<ans<<endl;
}
