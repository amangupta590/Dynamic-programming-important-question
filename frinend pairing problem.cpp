#include<bits/stdc++.h>
using namespace std;
int findmemo(int n,int dp[]){
	if(n==1 or n==2)
		return n;
	if(dp[n]!=-1)
		return dp[n];
	int stag=findmemo(n-1,dp);
	int pair=findmemo(n-2,dp);
	dp[n]=stag+pair*(n-1);
	return dp[n];
}
int finddp(int n){
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1]=1,dp[2]=2;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	cout<<findmemo(n,dp)<<endl;
	cout<<finddp(n);
}
