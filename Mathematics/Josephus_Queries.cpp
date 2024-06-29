#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int fungsi(int n,int k){
    if(n==1)return 1;
    if(k<=(n+1)/2){
        if(2*k>n)return (2*k)%n;
        else return 2*k;
    }
    int temp=fungsi(n/2,k-(n+1)/2);
    if(n%2==1){
        return temp*2+1;
    }else return temp*2-1;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int ans=fungsi(a,b);
        cout<<ans<<endl;
    
    }
}
