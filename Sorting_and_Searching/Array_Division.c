#include<bits/stdc++.h>
#define int long long
#define endl "\n"
 
using namespace std;
 
int n,k,ans;
vector<int> x;
int mid;
int r=0;
 
bool cek(){
    int sum=0;
    int banyak=1;
    for(int i=0;i<n;i++){
        if(x[i]>mid)return false;
        if((sum+x[i])>mid){
            sum=x[i];
            banyak++;
        }else{
            sum+=x[i];
        }
    }
    return (banyak<=k);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    x.resize(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        r+=x[i];
    }
    int l=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(cek()){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}
