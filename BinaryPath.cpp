#include<bits/stdc++.h>
using namespace std;

string solve(vector<vector<char>> grid, int i, int j, vector<vector<string>> &dp){
	if(i >= grid.size() || j >= grid[0].size()){
		return "-1";
	}
	
	if(i==grid.size()-1 && j==grid[0].size()-1){
		string st;
		st += grid[i][j];
		return st;
	}
	
	if(dp[i][j] != "*"){
		return dp[i][j];
	}
	
	string down = solve(grid, i+1, j, dp);
	string right = solve(grid, i, j+1, dp);
	
	string ret;
	ret += grid[i][j];
	if(down == "-1"){
		ret += right;
	}else if(right == "-1"){
		ret += down;
	}else{
		int val1 = 0, val2 = 0, k1 = down.size(), k2 = right.size();
		for(int p=0; p<down.size(); p++){
			if(down[p] == '1'){
				val1 += pow(2, k1);
			}
			k1--;
		}
		
		for(int q=0; q<right.size(); q++){
			if(right[i] == '1'){
				val2 += pow(2, k2);
			}
			k2--;
		}
		
		int r = min(val1, val2);
		//cout << "r->" << r << endl;
		if(r == val1){
			ret += down;
		}else{
			ret += right;
		}
	}
	
	//cout << i << " " << j << " ->" << ret << endl;
	dp[i][j] = ret;
	return dp[i][j];
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		int n; cin>>n;
		vector<vector<char>> grid;
		vector<char> row1;
		for(int i=0; i<n; i++){
			char ai;
			cin >> ai;
			row1.push_back(ai);
		}
		grid.push_back(row1);
		
		vector<char> row2;
		for(int j=0; j<n; j++){
			char bi; 
			cin >> bi;
			row2.push_back(bi);
		}
		grid.push_back(row2);
		vector<vector<string>> dp(2, vector<string>(n, "*"));
		cout << solve(grid, 0, 0, dp) << endl;
		
	}
}
