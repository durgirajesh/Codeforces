#include<bits/stdc++.h>
using namespace std;

int solve(string ele){
	unordered_map<string, int> mp;
	string tp;
	for(int i=0; i<ele.length()-1; i++){
		if(i == ele.length()-2){
			mp[tp]++;
		}		
		string sub = ele.substr(i+2);
		mp[tp+sub]++;
		
		tp += ele[i];
		
	}
	
	return mp.size();
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string latin; cin >> latin;
		
		cout << solve(latin) << endl;
	}
}
