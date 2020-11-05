#include<bits/stdc++.h>
using namespace std;
int findmemo(int dp[],int n){
    if(n==0 or n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    int d1=findmemo(dp,n-1);
    int d2=findmemo(dp,n-2);
    dp[n]=d1+d2;
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    cout<<findmemo(dp,n);
}
 
