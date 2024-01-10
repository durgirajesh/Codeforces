#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string str){
	unordered_map<char, bool> alphabets;
	for(int i=0; i<25; i++){
		alphabets.insert({char(i+97), false});
	}
	
	int balloons = 0;
	for(int i=0; i<str.length(); i++){
		if(!alphabets[str[i]]){
			balloons += 2;
			alphabets[str[i]] = true;
		}else{
			balloons += 1;
		}
	}
	
	return balloons;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string solvedproblems; cin >> solvedproblems;
		
		cout << solve(solvedproblems) << endl;
	}
	
	return 0;
}
