#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &ele, long long s, long long d, long long k){
	long long answer = 0;
	int i = s, j = 1;
	while(i <= ele.size() && j <= k){
		answer += (ele[i-1]*j);
		j++;
		i = s + d*(j-1);

	}
	
	return answer;
}

void out(vector<long long> arr){
	for(long long i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	long long t; cin >> t;
	while(t--){
		long long n, q;
		cin >> n >> q;
		
		vector<long long> ele;
		for(long long i=0; i<n; i++){
			long long ai; cin >> ai;
			ele.push_back(ai);
		}
		
		vector<long long> result;
		while(q--){
			long long s, d, k; cin >> s >> d >> k;
			result.push_back(solve(ele, s, d, k));
		}
		out(result);
	}
	return 0;
}


