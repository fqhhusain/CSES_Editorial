#include <bits/stdc++.h>
 
using namespace std;
 
    int n;
    int mod=1e9+7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin>>n;
    vector <int> myv(n+1,0);
    myv[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 && i-j>=0;j++){
                (myv[i]+=myv[i-j]) %= mod;
        }
    }
    cout<<myv[n]<<endl;
    
}
