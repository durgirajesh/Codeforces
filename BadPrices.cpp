#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices){
	int days = 0, bad = prices[prices.size()-1];
	for(int i=prices.size()-1; i>=0; i--){
		if(prices[i] <= bad){
			bad = prices[i];
		}else{
			days++;
		}
	}
	return days;
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		vector<int> prices;
		for(int i=0; i<n; i++){
			int ai; cin >> ai;
			prices.push_back(ai);
		}
		cout << solve(prices) << endl;
	}
	return 0;
}


