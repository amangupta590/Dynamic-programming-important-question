#include<bits/stdc++.h>
using namespace std;
int finddp(int n,int dp[]){
	if(n<=0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	int counti=INT_MAX;
	for(int i=1;i*i<=n;i++){
		int mera=finddp(n-i*i,dp)+1;
		counti=min(counti,mera);
	}
	dp[n]=counti;
	return dp[n];
}
int findd(int n){
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		int maxi=INT_MAX;
		for(int j=1;j*j<=i;j++){
			int mera=dp[i-j*j]+1;
			maxi=min(maxi,mera);
		}
		dp[i]=maxi;
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	cout<<finddp(n,dp)<<endl;
	cout<<findd(n);
	return 0;
}
