#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
	int count = 0;
	for(int i=0; i<arr.size()-1; i++){
		for(int j=i+1; j<arr.size(); j++){
			if((j-i) == arr[j] - arr[i]){
				count++;
			}
		}
	}
	return count;
}

void out(vector<string> arr){
	for(long long i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}
}

int main(){
	long long t; cin >> t;
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


