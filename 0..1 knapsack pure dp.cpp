#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(a,b) for(int i=a;i<b;i++)
#define mod 1000000007
//int find(int idx,int w,int val[],int wt[],int n,vector<vector<int>>&dp){
//	if(idx>=n){
//		return 0;
//	}
//	if(w==0)
//		return 0;
//	if(dp[idx][w]!=-1)
//		return dp[idx][w];
//	if(wt[idx]<=w){
//		int count1=val[idx]+find(idx+1,w-wt[idx],val,wt,n,dp);
//		int count2=find(idx+1,w,val,wt,n,dp);
//		return dp[idx][w]=max(count1,count2);
//	}
//	else 
//		return dp[idx][w]=find(idx+1,w,val,wt,n,dp);	
//}
int find(int wt[],int val[],int n,int w){
	vector<vector<int>>dp(n+1,vector<int>(w+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0 or j==0)
				dp[i][j]=0;
			else if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	return dp[n][w];
}
int main(){
	int wt[]={25,25,30};
	int val[]={100,100,180};
	int n=3;
	int weight=50;
//	vector<vector<int>>dp(n,vector<int>(weight+1,-1));
	cout<<find(wt,val,n,weight)<<endl;
	return 0;
}
