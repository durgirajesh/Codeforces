#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &elements){
	unordered_map<int, int> freq;
	for(int i=0; i<elements.size(); i++){
		freq[elements[i]]++;
	}
	
	int moves = 0;
	for(int i=0; i<elements.size(); i++){
		if(freq[elements[i]] != 1){
			freq[elements[i]]--;
			
			int diff = abs(moves - (i+1));
			moves += diff;	
		}
	}
	
	return moves;
}

void out(vector<int> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> elements;
		
		for(int i=0; i<n; i++){
			int element; cin >> element;
			elements.push_back(element);
		}
		
		cout << solve(elements) << endl;
	}
	
	return 0;
}
