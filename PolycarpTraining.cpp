#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &contests){
	int k = 1, days = 0;
	set<int> pblms;
	for(int i=0; i<contests.size(); i++){
		pblms.insert(contests[i]);
	}
	
	for(auto it : pblms){
		if(it < k){
			break;
		}
		days++;
		k++;
	}
	return days;
}

int main(){
	int n; cin >> n;
	vector<int> contests; 
	for(int i=0; i<n; i++){
		int x; cin >> x;
		contests.push_back(x);
	}
	
	cout << solve(contests);
	return 0;
}


