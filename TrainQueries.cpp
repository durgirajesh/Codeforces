#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> &stat, int a, int b){
	bool start = true, end = false;
	for(int i=0; i<stat.size(); i++){
		if(stat[i] == a && !start){
			start = false;
			for(int j=i+1; j<stat.size(); j++){
				if(stat[j] == b){
					end = false;
					break;
				}
			}
		}
	}
	
	string result = (start && end) ? "yes" : "No";
	return result;
}

void out(vector<string> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}
}

int main(){
	long long t; cin >> t;
	while(t--){
		
		int n, k;
		cin >> n >> k;
		vector<int> stations;
		
		for(int i=0; i<n; i++){
			int ui; cin >> ui;
			stations.push_back(ui);
		}
		
		vector<string> result;
		while(k--){
			int ai, bi; cin >> ai >> bi;
			string ans = solve(stations, ai, bi);
			
			result.push_back(ans);
		}
		
		out(result);
	}
	return 0;
}


