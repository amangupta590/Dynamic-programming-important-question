	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long int
	#define mod 1000000007
	int count=0;
	//Recursion method//
	void findmy(vector<int>&nums,int tar,int n,int sum){
	    if(n==nums.size()){
	        if(tar==sum)
	            count++;
	        return ;
	    }
	    findmy(nums,tar,n+1,sum+nums[n]);
	    findmy(nums,tar,n+1,sum-nums[n]);
	}
// memoization 
 	int findmy(vector<int>&nums,int tar,int si,int sum,unordered_map<string,int>&h){
        string key=to_string(si)+" "+to_string(sum);
        if(h.count(key))
            return h[key];
        if(si==nums.size()){
            if(sum==tar){
                return 1;
            }
            else
                return 0;
        }
        int positive=findmy(nums,tar,si+1,sum+nums[si],h);
        int negative=findmy(nums,tar,si+1,sum-nums[si],h);
        int total=positive+negative;
        h[key]=total;
        return total;
    }
	int main(){
		vector<int>arr(5,1);
		int target;
		cin>>target;
		findmy(arr,target,0,0);
		cout<<count<<endl;
		return 0;
	}

