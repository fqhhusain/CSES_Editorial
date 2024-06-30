#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n,m;
vector<pair<int,pair<int,int>>> edge;
vector<int> par;
vector<int> siz;
 
int cari(int x){
    if(par[x]==x)return x;
    return par[x]=cari(par[x]);
}
 
bool cek(int x,int y){
    return par[x]==par[y];
}
void gabung(int x,int y,int v){
    int cx=cari(x);
    int cy=cari(y);
    if(cx==cy)return;
    if(siz[cx]<siz[cy])swap(cx,cy);
    par[cy]=cx;
    siz[cx]+=(v+siz[cy]);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    par.resize(n+1);
    siz.resize(n+1,0);
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<m;i++){
        int ax,bx,vx;
        ax=edge[i].second.second;
        bx=edge[i].second.first;
        vx=edge[i].first;
        if(!cek(ax,bx)){
            gabung(ax,bx,vx);
        }
    }
    int parall=cari(1);
    for(int i=1;i<=n;i++){
        int tmp=cari(i);
        if(tmp!=parall){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<siz[par[1]]<<endl;
}
