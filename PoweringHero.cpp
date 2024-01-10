#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &deck){
	priority_queue<long long> bonus; 
	long long power = 0;
	for(long long i=0; i<deck.size(); i++){
		if(deck[i] > 0){
			bonus.push(deck[i]);
		}else{
			if(!bonus.empty()){
				power += bonus.top();
				bonus.pop();
			}
		}
	}
	
	return power;
}

int main(){
	long long t; cin >> t;
	while(t--){
		long long n; cin >> n;
		vector<long long> cards;
		
		for(long long i=0; i<n; i++){
			long long si ; cin >> si;
			cards.push_back(si);
		}
		cout << solve(cards) << endl;
	}
	return 0;
}
