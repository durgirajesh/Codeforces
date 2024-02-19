#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<char> coins, vector<int> &dp, int index){

	if(index >= coins.size()){
		return -2;
	}
	
	if(dp[index] != -1){
		return dp[index];
	}
	
	if(coins[index] == '*'){
		return 0;
	}
	
	if(coins[index] == '.'){
		dp[index] = 0;
	}
	else{
		dp[index] = 1;
	}
	
	int step1 = 0, step2 = 0;
	if((index + 1) <= coins.size() -1 && (index + 1) != '*'){
		step1 = solve(coins, dp, index + 1);
	}
	
	if((index + 2) <= coins.size() -1 && (index + 2) != '*'){
		step2 = solve(coins, dp, index + 2);
	}
	
	dp[index] += max(step1, step2);
	return dp[index];
}

int main(){
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<char> coins; 
		
		for(ll i=0; i < n; i++){
			char ch; cin >> ch;
			coins.push_back(ch);
		}
		
		vector<int> dp(coins.size(), -1);
		cout << max(solve(coins, dp, 0), solve(coins, dp, 1)) << endl;
	}
	return 0;
}


