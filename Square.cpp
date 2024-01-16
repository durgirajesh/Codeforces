#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid){
	int area = 0;
	for(int i=0; i<grid.size()-1; i++){
		for(int j = i+1; j<grid.size(); j++){
			if(grid[i][0] == grid[j][0]){
				area = pow(abs(grid[i][1]-grid[j][1]), 2);
				break;
			}
		}
	}
	
	return area;
}

int main(){
	int t; cin >> t;
	while(t--){
		vector<vector<int>> coordinates;
		for(int i=0; i<4; i++){
			int xi, yi; cin >> xi >> yi;
			vector<int> points = {xi, yi};
			coordinates.push_back(points);
		}
		cout << solve(coordinates) << endl;
	}
	
	return 0;
}
