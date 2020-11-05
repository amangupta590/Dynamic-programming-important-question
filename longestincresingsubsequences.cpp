#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int
#define mod 1000000007
int main(){
	vector<int>arr(8);
	for(int i=0;i<7;i++){
		cin>>arr[i];
	}
	int dp[8];
	memset(dp,1,sizeof(dp));
	for(int i=1;i<=7;i++){
		int maxi=1;
		for(int j=0;j<i;j++){
			if(arr[j]<=arr[i]){
				maxi=max(maxi,dp[j]);
			}
		}
		dp[i]=maxi+1;
	}
	int m=0;
	for(int i=0;i<=7;i++){
		cout<<dp[i]<<" ";
	}
	cout<<m<<endl;
	return 0;
}

