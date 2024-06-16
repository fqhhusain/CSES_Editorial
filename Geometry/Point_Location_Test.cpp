#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int x1,y11,x2,y2,x3,y3,n;
 
int cross(int xa,int ya,int xb,int yb){
    return (xa*yb-xb*ya);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x1>>y11>>x2>>y2>>x3>>y3;
        x2-=x1;
        y2-=y11;
        x3-=x1;
        y3-=y11;
        int point=cross(x3,y3,x2,y2);
        if(point<0){
            cout<<"LEFT"<<endl;
        }else if(point>0 ){
            cout<<"RIGHT"<<endl;
        }else{
            cout<<"TOUCH"<<endl;
        }
    }
}
