#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> &arr){
	sort(arr.begin(), arr.end());
	int maxsum = 0;
	
	for(int i=1; i<arr.size(); i++){
		maxsum += abs(arr[i-1] - arr[i]);
	}
	
	return maxsum;
}
	
int main(){
	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		vector<int> arr;
		for(int i=0; i<n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}
		
		cout << solve(arr) << endl;
	}
	return 0;
}


