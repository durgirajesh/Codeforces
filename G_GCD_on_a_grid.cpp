#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd_(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd_grid(vector<vector<int>> grid, vector<vector<int>> &dp, int i, int j){
    if( i >= grid.size() || j >= grid[i].size()){
        return 1;
    }

    if(i == grid.size()-1 && j == grid[i].size()-1){
        return grid[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = gcd_grid(grid, dp, i, j+1);
    int down = gcd_grid(grid, dp, i+1, j);

    dp[i][j] = max(gcd_(grid[i][j], right), gcd_(grid[i][j], down));
    return dp[i][j];
}

int main(){
	ll t; cin >> t;
	while(t--){
		int n, m;
        cin >> n >> m;

        vector<vector<int>> grid;
        for(int i=0; i < n; i++){
            vector<int> row;
            for(int j=0; j<m; j++){
                int aij; 
                cin >> aij;

                row.push_back(aij);
            }

            grid.push_back(row);
        }

        vector<vector<int>> dp(n, vector<int> (m, -1));
        cout << gcd_grid(grid, dp, 0, 0) << endl; 
	}
	return 0;
}


