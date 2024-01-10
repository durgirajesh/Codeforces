#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr){
	priority_queue<int> pq;
	for(int i=0; i<arr.size(); i++){
		pq.push(arr[i]);
	}
	
	for(int i=0; i<arr.size(); i++){
		if(arr[i] == pq.top()){
			int x = pq.top();
			pq.pop();
			arr[i] -= pq.top();
			
			pq.push(x);
		}else{
			arr[i] -= pq.top();
		}
	}
	return arr;
}

void out(vector<int> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t > 0){
		int n; cin >> n;
		vector<int> strength;
		for(int i=0; i<n; i++){
			int x; cin >> x;
			strength.push_back(x);
		}
		vector<int> maxstr = solve(strength);
		out(maxstr);
		
		t--;
	}
	return 0;
}
