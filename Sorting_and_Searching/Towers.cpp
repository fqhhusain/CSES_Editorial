#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> multi;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(multi.upper_bound(temp)!=multi.end()){
            multi.erase(multi.upper_bound(temp));
        }
        multi.insert(temp);
    }
    cout<<multi.size()<<endl;
}
