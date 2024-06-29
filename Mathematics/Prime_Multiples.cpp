#include<bits/stdc++.h>
#define int long long
 
using namespace std;
int n,k,hasil;
vector <int> bil;
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        bil.push_back(a);
    }
    vector <int> count (k+1);
    for(int mask=1;mask<(1<<k);mask++){
        int digit=0;
        int temp=n;
        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                digit++;
                temp /= bil[i];
            }
        }
        count[digit]+=temp;
    }
    for(int i=1;i<=k;i++){
        if(i%2==0){
            hasil-=count[i];
        }else{
            hasil+=count[i];
        }
    }
    cout<<hasil<<endl;
}
