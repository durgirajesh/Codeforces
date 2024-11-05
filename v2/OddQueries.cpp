#include<bits/stdc++.h>
using namespace std;

string odd_queries(vector<int> &arr, int &l, int &r, int &k) {
	int total_sum = arr[arr.size() - 1], subarr_sum = ( arr[r - 1] - ( l > 1 ? arr[l - 2] : 0) );
	return ( (total_sum - subarr_sum) + k * ((r - l) + 1) ) % 2 != 0 ? "YeS" : "No" ;
}

vector<int> get_prefix_arr(vector<int> &arr) {
	vector<int> prefix_arr ;
	int i = 0, curr_sum = 0 ;

	while ( i < arr.size() ) {
		curr_sum += arr[i] ;
		prefix_arr.push_back(curr_sum) ;
		i += 1 ;
	}
	return prefix_arr ;
}

int main() {
	int t ;
	cin >> t;

	while (t > 0) {
		int n, q ;
		vector<int> arr ;

		cin >> n >> q ;
		while (n > 0) {
			int x ;
			cin >> x;
			arr.push_back(x);
			n -= 1 ;
		}

		vector<int> prefix_arr = get_prefix_arr(arr) ;
		while (q > 0) {
			int l, r, k ;
			cin >> l >> r >> k ;
			cout << odd_queries(prefix_arr, l, r, k) << endl ;
			q -= 1;
		}
		t -= 1 ;
	}

	return 0;
}