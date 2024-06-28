#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<utility>
#include<string>
#include<vector>
#include <stdio.h>
 
#define int long long
 
using namespace std;
 
int n;
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    if(n<=3){
        cout<<"NO SOLUTION"<<endl;
    }
    for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    } 
    
}
