#include<bits/stdc++.h>
using namespace std;

int solve(string black){
	int first = -1, last = -1;
	for(int i=0; i<black.size(); i++){
		if(black[i] == 'B'){
			if(first == -1){
				first = i;
			}
			
			last = i;
		}
	}
	
	
	
	return abs(first - last) + 1;
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n; cin >> n;
		string black; cin >> black;
		
		cout << solve(black) << endl;
	}
	return 0;
}


