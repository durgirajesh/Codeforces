#include<bits/stdc++.h>
using namespace std;

vector<string> solve(vector<long long> arr1, vector<vector<long long>> &arr2){
	vector<string> result;
	for(long long i=0; i<arr2.size(); i++){
		vector<long long> query = arr2[i];
		long long l = query[0], r = query[1], k = query[2], tpsum = 0;
		
		for(long long j=l-1; j<r; j++){
			tpsum += arr1[j] + abs(arr1[j]-k);
		}
		
		long long tsum = 0;
		for(long long p=0; p<arr1.size(); p++){
			if(p <= (r-1) && p >= (l-1)){
				continue;
			}
			tsum += arr1[p];
		}
		
		string flag = ((tpsum + tsum)%2 != 0) ? "YeS" : "nO";
		result.push_back(flag);
	}
	
	return result;
}

void out(vector<string> arr){
	for(long long i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}
}

int main(){
	long long t; cin >> t;
	while(t--){
		long long n,q; cin >> n >> q;
		
		vector<long long> arr;
		for(long long i=0; i<n; i++){
			long long xi; cin >> xi;
			arr.push_back(xi);
		}
		
		vector<vector<long long>> queries;
		for(long long i=0; i<q; i++){
			long long l, r, k; 
			cin >> l >> r >> k;
			
			vector<long long> qr = {l, r, k};
			queries.push_back(qr);
		}
		vector<string> answer = solve(arr, queries);
		out(answer);
	}
	
	return 0;
}
