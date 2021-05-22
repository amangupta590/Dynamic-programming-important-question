#include<bits/stdc++.h>
#define fr(i,a,n) for (int i = a; i<n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("./inp.txt", "r", stdin);
	freopen("./outp.txt", "w", stdout);
    #endif 
}
int cost[21][21];
int dp[21][1<<21];
int solve(int i,int &n,int mask){
	if(i==n)
		return 0;
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	int answer=INT_MAX;
	for(int j=0;j<n;j++){
		if(mask&(1<<j))
			answer=min(answer,cost[j][i]+solve(i+1,n,mask^(1<<j)));
	}
	return dp[i][mask]=answer;
}
int main(){
	init_code();
	int t;
	t=1;
	while(t--){
		memset(dp,-1,sizeof dp);
		int n;
		cin>>n;
		fr(i,0,n)
			fr(j,0,n)
				cin>>cost[i][j];
		cout<<solve(0,n,(1<<n)-1);
	}
	return 0;
}