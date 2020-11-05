#include<bits/stdc++.h>
using namespace std;
int reducetoone(int n,int dp[]){
	if(n==1)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	int cnt1=INT_MAX,cnt2=INT_MAX,cnt3=INT_MAX;
	if(n%2==0)
		cnt1=reducetoone(n/2,dp)+1;
	if(n%3==0)
		cnt2=reducetoone(n/3,dp)+1;
	cnt3=reducetoone(n-1,dp)+1;
	dp[n]=min(cnt1,min(cnt2,cnt3));
	return dp[n]; 
}
int reducetoonedp(int n){
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int l1=INT_MAX,l2=INT_MAX,l3=INT_MAX;
		if(i%2==0)
			l1=dp[i/2]+1;
		if(i%3==0)
			l2=dp[i/3]+1;
		l3=dp[i-1]+1;
		dp[i]=min(l1,min(l2,l3));
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	cout<<reducetoone(n,dp)<<endl;;
	cout<<reducetoonedp(n);
}
