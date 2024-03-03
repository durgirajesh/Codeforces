#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){
	int minutes = 4*60, left = 0;
	left = (minutes - k);
	int solved = 0, timePassed = 5, mult = 2;
	if(left >= 0){
		while(timePassed <= left){
			timePassed += 5*mult;
			solved++;
			mult++;
		}
	}
	
	if(solved > n){
		return n;
	}
	return solved;
}

int main(){
	int n, k;
	cin >> n >> k;
	
	cout << solve(n, k) << endl;
}
