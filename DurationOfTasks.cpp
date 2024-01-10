#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr1, vector<int> &arr2){
	queue<int> queue;
	vector<int> time;
	for(int i=0; i<arr1.size(); i++){
		int duration = 0;
		if(i+1 < arr1.size() && arr1[i+1] < arr2[i]){
			if(!queue.empty()){
				duration = abs(queue.front() - arr2[i]);
				queue.pop();
			}else{
				duration = abs(arr1[i] - arr2[i]);
			}
			queue.push(arr2[i]);
		}
		else{
			if(!queue.empty()){
				duration = abs(queue.front() - arr2[i]);
				queue.pop();
			}else{
				duration = abs(arr1[i] - arr2[i]);
			}
		}
		time.push_back(duration);
	}
	return time;
}


void out(vector<int> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int t ; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> start, end;
		
		for(int i=0; i<n; i++){
			int si; cin >> si;
			start.push_back(si);
		}
		
		for(int j=0; j<n; j++){
			int fi; cin >> fi;
			end.push_back(fi);
		}
		
		vector<int> duration = solve(start, end);
		out(duration);
	}
	
	return 0;
}
