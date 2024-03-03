#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<int> denom, vector<ll> &dp, ll amt){
	if(amt < 0){
		return -1;
	}
	
	if(amt == 0){
		return 0;
	}
	
	if(dp[amt] != -1){
		return dp[amt];
	}
	
	int coins = INT_MAX;
	for(int i=0; i<denom.size(); i++){
		int s = solve(denom, dp, amt - denom[i]);
		if(s != -1){
			s += 1;
			coins = min(coins, s);
		}
	}
	
	dp[amt] = coins;
	return dp[amt];
}

int main(){
	vector<int> denom = {1, 5, 10, 20, 100};
	ll n; cin >> n;
	vector<ll> dp(INT_MAX, -1);
		
	cout << solve(denom, dp, n) << endl;
	return 0;
}


