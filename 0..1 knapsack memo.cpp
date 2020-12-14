#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(a,b) for(int i=a;i<b;i++)
#define mod 1000000007
int find(int idx,int w,int val[],int wt[],int n,vector<vector<int>>&dp){
	if(idx>=n){
		return 0;
	}
	if(w==0)
		return 0;
	if(dp[idx][w]!=-1)
		return dp[idx][w];
	if(wt[idx]<=w){
		int count1=val[idx]+find(idx+1,w-wt[idx],val,wt,n,dp);
		int count2=find(idx+1,w,val,wt,n,dp);
		return dp[idx][w]=max(count1,count2);
	}
	else 
		return dp[idx][w]=find(idx+1,w,val,wt,n,dp);	
}
int main(){
	int wt[]={25,25,30};
	int val[]={100,100,180};
	int n=3;
	int weight=50;
	vector<vector<int>>dp(n,vector<int>(weight+1,-1));
	cout<<find(0,weight,val,wt,n,dp);
	return 0;
}
