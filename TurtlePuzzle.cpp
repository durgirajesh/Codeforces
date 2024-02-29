#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr){
	int sum = 0;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] < 0){
			arr[i] = -arr[i];
		}
		sum += arr[i];
	}
	
	return sum;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++){
			int ai;
			cin >> ai;
			v.push_back(ai);
		}
		
		cout << solve(v) << endl;
	}
}
