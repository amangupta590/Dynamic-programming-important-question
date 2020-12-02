#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main(){
	int n,x;
	cin>>n>>x;
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int dp[n+1][x+1];
	for(int i=1;i<=n;i++){
		for(int sum=0;sum<=x;sum++){
			if(sum==0)
				dp[i][sum]=1;
			else{
				int op1=(i==1)?0:dp[i-1][sum];
				int op2=(arr[i]>sum)?0:dp[i][sum-arr[i]];
				dp[i][sum]=(op1+op2)%mod;
			}
		}
	}
	cout<<dp[n][x]<<endl;
	return 0;
}

