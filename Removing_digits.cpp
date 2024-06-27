#include<bits/stdc++.h>
 
using namespace std;
vector<int> digit;
void cari_digit(int num){
    if(num>9){
        cari_digit(num/10);
    }
    digit.push_back(num%10);
}
 
int main(){
    int n;
    cin>>n;
    vector <int> dp(n+1,2e9);
    dp[0]=0;
    for(int j=1;j<=n;j++){
        digit.clear();
        cari_digit(j);
        
    for(int i=0;i<digit.size();i++){
        if(j-digit[i]>=0){
            dp[j]=min(dp[j],1+dp[j-digit[i]]);
        }
    }
    }
    cout<<dp[n]<<endl;
}
