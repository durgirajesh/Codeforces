#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> con){
	if(con.size() == 1){
		return "YEs";
	}
	int avg = 0;
	for(int i=0; i<con.size(); i++){
		avg += con[i];
	}
	avg /= con.size();
	
	int sum = 0;
	for(int i=0; i<con.size(); i++){
		if(con[i] < avg){
			if(sum <= 0){
				return "No";
			}
			sum -= abs(con[i] - avg);
		}else if(con[i] > avg){
			if(sum < 0){
				return "nO";x	x		
			}
			sum += abs(avg - con[i]);
		}
	}
	
	if(sum != 0){
		return "No";
	}
	
	return "Yes";
}

int main(){
	int t; cin >> t;
	while(t>0){
		int n; cin >> n;
		
		vector<int> container;
		for(int i=0; i<n; i++){
			int ai; cin >> ai;
			container.push_back(ai);
		}
		
		cout << solve(container) << endl;
		t--;
	}
}
