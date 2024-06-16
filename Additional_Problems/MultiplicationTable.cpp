#include<bits/stdc++.h>
#define int long long
#define endl "\n"
 
using namespace std;
 
int n,ans;
int mid;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int l=1;
    int r=n*n;
    while(l<r){
        mid=l+(r-l)/2;
        int leq=0;
        int med=(n*n+1)/2;
        for(int i=1;i<=n;i++){
            leq+=min(n,mid/i);
        }
        if(med<=leq){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r<<endl;
}
