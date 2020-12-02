#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int find(vector<ll>&arr,ll n,ll desired,vector<ll>&dp){
    if(desired==0){
        return 1;
    }
    if(desired<0)
        return -1;
    if(dp[desired]!=-1)
        return dp[desired];
    
    int count=0;
    for(ll i=0;i<n;i++){
        if(desired-arr[i]>=0){
            count=(count%mod+find(arr,n,desired-arr[i],dp)%mod)%mod;
        }
    }
    dp[desired]=count;
    return dp[desired];
}

int main() {
    ll n,sumi;
    cin>>n>>sumi;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>dp(sumi+1,-1);
    cout<<find(arr,n,sumi,dp)%mod<<endl;;
}
