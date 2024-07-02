#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
vector<vector<int> > edge;
vector<int> par;
vector<bool> pernah;
int sv,ev;
 
bool fungsi(int idx,int p){
    pernah[idx]=true;
    par[idx]=p;
    for(auto x : edge[idx]){
        if(x==p)continue;
        if(pernah[x]){
           sv=x;
           ev=idx;
           return true; 
        }
        if(!pernah[x]){
            if(fungsi(x,idx))return true;
        }
    }
    return false;
}
bool bisa(){
    for(int i=1;i<=n;i++){
        if(!pernah[i])
            if(fungsi(i,-1))return true;
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    edge.resize(n+1);
    pernah.resize(n+1);
    par.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    if(!bisa()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int tv=ev;
    vector<int> ans;
    ans.push_back(ev);
    while(tv!=sv){
        tv=par[tv];
        ans.push_back(tv);
    }
    ans.push_back(ev);
    cout<<ans.size()<<endl;
    for(auto c : ans){
        cout<<c<<" ";
    }
}
