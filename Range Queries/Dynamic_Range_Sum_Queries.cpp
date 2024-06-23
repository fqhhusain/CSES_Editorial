#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n,q;
vector<int> arr;
vector<int> seg;
 
void build(int k=1,int l=0,int r=(n-1)){
    if(l==r){
        seg[k]=arr[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    seg[k]=seg[k*2]+seg[k*2+1];
}
void update(int k,int u,int id=1,int l=0,int r=n-1){
    if(l==r){
        seg[id]=u;
        return;
    }
    int mid=l+(r-l)/2;
    if(k<=mid){
        update(k,u,id*2,l,mid);
    }else{
        update(k,u,id*2+1,mid+1,r);
    }
    seg[id]=seg[id*2]+seg[id*2+1];
}
int quer(int a,int b,int id=1,int l=0,int r=n-1){
    if(a<=l && r<=b){
        return seg[id];
    }
    if(b<l || a>r){
        return 0;
    }
    int mid=l+(r-l)/2;
    return quer(a,b,id*2,l,mid)+quer(a,b,id*2+1,mid+1,r);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    arr.resize(n+1);
    seg.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build();
    for(int i=0;i<q;i++){
        int typ,a,b;
        cin>>typ;
        if(typ==1){
            cin>>a>>b;
            a--;
            update(a,b);
        }else{
            cin>>a>>b;
            a--;
            b--;
            cout<<quer(a,b)<<endl;
        }
    }
 
}
