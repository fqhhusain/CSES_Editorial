#include<bits/stdc++.h>
#define int long long
#define endl "\n"
 
using namespace std;
 
signed main(){
 ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    map <int,int> cmp;
    vector<int> a(n),b(n),p(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>p[i];
        b[i]++;
        cmp[a[i]],cmp[b[i]];
    }
    int count=0;
    for(auto&v : cmp){
        v.second=count++;
    }
    vector<vector<pair<int,int>>> edge(count);
    for(int i=0;i<n;i++){
        edge[cmp[b[i]]].emplace_back(cmp[a[i]],p[i]);
    }
    vector<int> dist(count,0);
    for(int i=0;i<count;i++){
        if(i>0)dist[i]=dist[i-1];
        for(auto u : edge[i]){
            dist[i]=max(dist[i],dist[u.first]+u.second);
        }
    }
    cout<<dist[count-1]<<endl;
}
