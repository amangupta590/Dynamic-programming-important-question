#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int dp[10000][10000];
int longestcommonsubsequencesmemo(string s1,string s2){
	if(s1.size()==0 or s2.size()==0){
		dp[s1.size()][s2.size()]=0;
		return 0;
	}
	if(dp[s1.size()][s2.size()]!=-1)
		return dp[s1.size()][s2.size()];
	char ch1=s1[0];
	char ch2=s2[0];
	string ros1=s1.substr(1);
	string ros2=s2.substr(1);
	int result;
	if(ch1==ch2){
		result= 1+longestcommonsubsequencesmemo(ros1,ros2);
	}
	else{
		int firstchoice=longestcommonsubsequencesmemo(s1,ros2);
		int secchoice=longestcommonsubsequencesmemo(ros1,s2); 
		result=max(firstchoice,secchoice);
	}
	dp[s1.size()][s2.size()]=result;
	return result;
}
int longestcommonsubsequences(string s1,string s2){
	if(s1.size()==0 or s2.size()==0)
		return 0;
	char ch1=s1[0];
	char ch2=s2[0];
	string ros1=s1.substr(1);
	string ros2=s2.substr(1);
	if(ch1==ch2){
		return 1+longestcommonsubsequences(ros1,ros2);
	}
	else{
		int firstchoice=longestcommonsubsequences(s1,ros2);
		int secchoice=longestcommonsubsequences(ros1,s2); 
		return max(firstchoice,secchoice);
	}
}
int main(){
	cout<<longestcommonsubsequences("abcdef","ghcdke")<<endl;
	return 0;
}

