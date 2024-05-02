#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
char table[9][9];
int ans;
int col[9];
int dig1[20];
int dig2[20];
 
void solve(int id){
    if(id>8){
       ans++;
       return;
    }
    for(int i=1;i<=8;i++){
        if(table[id][i]=='*')continue;
        if(col[i] || dig1[id+i] || dig2[i-id+8])continue;
        col[i]=1;
        dig1[id+i]=1;
        dig2[i-id+8]=1;
        solve(id+1);
        col[i]=0;
        dig1[id+i]=0;
        dig2[i-id+8]=0;
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>table[i][j];
        }
    }
    solve(1);
    cout<<ans<<endl;
}
