#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, vector<int> b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int diff = 0, i1 = 0, i2 = 0, j = a.size()-1, k = b.size()-1, iter = 0;
	while(iter < a.size()){
		if(iter%2 == 0){
			if(abs(a[i1]-b[k]) > abs(a[i1]-b[i2])){
				diff += abs(a[i1]-b[k]);
				k--;
				i1++;
			}else{
				diff += abs(a[i1]-b[i2]);
				i2++;
			}
		}else{
			if(abs(b[i2]-a[j]) > abs(b[k]-a[j])){
				diff += abs(b[i2]-a[j]);
				i2++; j--;
			}else{
				diff += abs(b[k]-a[j]);
				k--;
			}
		}
		iter++;
	}
	
	return diff;
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		vector<int> an, am;
		
		for(int i=0; i<n; i++){
			int ai; cin >> ai;
			an.push_back(ai);
		}
		
		for(int j=0; j<m; j++){
			int aj ; cin >> aj;
			am.push_back(aj);
		}
		
		cout << solve(an, am) << endl;
	}
	return 0;
}


