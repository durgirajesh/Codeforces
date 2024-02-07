#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> solve(vector<ll> &arr, ll l, ll r, vector<ll> &dp){
	vector<ll> answer;
	ll first = -1, last = -1;
	
	for(int i=(l-1); i<=(r-1); i++){
		if(i >= 0 && i <= arr.size()-1){
			if(first == -1){
				first = (i+1);
			}else if((first-1) >= 0 && (first-1) <= arr.size()- 1){
				if(arr[first-1] != arr[i]){
					last = i+1;
				}
			}
		}
	}

	
	if(first == -1 || last == -1){
		return {-1, -1};
	}
	
	return {first, last};
}

void out(vector<ll> arr){
	for(ll i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main(){
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> a;
		for(ll i=0; i<n; i++){
			ll x; cin >> x;
			a.push_back(x);
		}
		
		ll k; cin >> k;
		while(k--){
			ll l, r; cin >> l >> r;
			vector<ll> dp;
			vector<ll> result = solve(a, l, r, dp);
			out(result);
		}
		cout << endl;
	}
	return 0;
}


