#include<bits/stdc++.h>
using namespace std;

int solve(string s, string f){
	int add = 0, rem = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i] == '1' && f[i] == '0'){
			rem++;
		}
		else if(s[i] == '0' && f[i] == '1'){
			add++;
		}
	}
	
	return max(add, rem);
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s, f; cin >> s >> f;
		cout << solve(s, f) << endl;
	}
	return 0;
}


