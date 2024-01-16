#include<bits/stdc++.h>
using namespace std;

vector<string> solve(vector<string> &request){
	vector<string> result;
	unordered_map<string, int> db; 
	
	for(int i=0; i<request.size(); i++){
		if(db.find(request[i]) != db.end()){
			string response = request[i] + to_string(db[request[i]]);
			result.push_back(response);
		}else{
			result.push_back("OK");
		}
		
		db[request[i]]++;
	}
	
	return result;
}

void out(vector<string> &arr){
	for(long long i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}
}

int main(){
	int n ; cin >> n;
	vector<string> request;
	while(n > 0){
		string letters; cin >> letters;
		request.push_back(letters);
		
		n--;
	}
	
	vector<string> response = solve(request);
	out(response);
	
	return 0;
}
