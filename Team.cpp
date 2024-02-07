#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid){
	int ans = 0;
	for(int i=0; i<grid.size(); i++){
		int conf = 0;
		for(int j=0; j<grid[i].size(); j++){
			conf += grid[i][j];
		}
		
		if(conf >= 2){
			ans += 1;
		}
	}
	
	return ans;
}

int main(){
	long long n; cin >> n;
	vector<vector<int>> view;
	while(n--){
		int k = 3;
		vector<int> v;
		while(k--){
			int x; cin >> x;
			v.push_back(x);
		}
		
		view.push_back(v);
	}
	
	cout << solve(view);
	return 0;
}


