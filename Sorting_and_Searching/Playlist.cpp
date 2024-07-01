#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n,hasil;
map<int,int> pos;
int l,r;
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    l=1;
    for(int i=1;i<=n;i++){
        int temp,ht;
        cin>>temp;
        l=max(l,pos[temp]+1);
        pos[temp]=i;
        ht=i-l+1;
        hasil=max(hasil,ht);
    }
    cout<<hasil<<endl;
}
