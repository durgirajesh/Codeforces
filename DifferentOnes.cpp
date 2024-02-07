#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> a1, vector<int> a2, int k){
	set<int> ele1, ele2, main;
	for(int i=0; i<a1.size(); i++){
		if(a1[i] <= k){
			ele1.insert(a1[i]);
			main.insert(a1[i]);
		}
	}
	
	for(int j=0; j<a2.size(); j++){
		if(a2[j] <= k){
			ele2.insert(a2[j]);
			main.insert(a2[j]);
		}
	}
	
	int p = (k/2);
	if(ele1.size() >= p && ele2.size() >= p && main.size() == k){
		return "Yes";
	}
	
	return "No";
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> a1, a2;
		for(int i=0; i<n; i++){
			int x; cin >> x;
			a1.push_back(x);
		}
		
		for(int j=0; j<m; j++){
			int y; cin >> y;
			a2.push_back(y);
		}
		
		cout << solve(a1, a2, k) << endl;
	}
	return 0;
}


