#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main(){
    int n;
    vector<int> hasil(1e6+5,0);
    cin>>n;
    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            hasil[j]++;
        }
    }
    while(n--){
        int x;
        cin>>x;
        cout<<hasil[x]<<endl;
    }
}
