#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int nums[1000001];
int find(vector<int>&arr,int n,int total){
	nums[0]=1;
	for(int i=0;i<n;i++){
		int curr=arr[i];
		for(int j=total;j>=curr;j--){
			if(nums[j]!=0 or nums[j-curr]==0)
				continue;
			else
				nums[j]=1;
		}
	}
	if(nums[total]==0)
		return 0;
	else
		return 1;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(sum%2==1)
		cout<<"not valid";
	else 
		if(find(arr,n,sum/2))
			cout<<"yes could"<<endl;
		else
			cout<<"nope"<<endl;
	return 0;
}

