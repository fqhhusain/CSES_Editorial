#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n,m;
vector<vector<char>> grid;
int hor[]={0,0,1,-1};
int ver[]={1,-1,0,0};
 
void fill(int x,int y){
    grid[x][y]='#';
    for(int i=0;i<4;i++){
        int tx=x+hor[i];
        int ty=y+ver[i];
        if(tx<1 || ty<1 || tx>n || ty>m)continue;
        if(grid[tx][ty]=='#')continue;
        fill(tx,ty);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    grid.resize(n+1);
    for(int i=1;i<=n;i++){
        grid[i].resize(m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='.'){
                fill(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
