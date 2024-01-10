#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &ratings, string &review){
	priority_queue<int> q;
	map<int, int> like, dislike;
	
	for(int i=0; i<review.size(); i++){
		q.push(ratings[i]);
		if(review[i] == '1'){
			like.insert({-ratings[i], i});
		}else{
			dislike.insert({-ratings[i], i});
		}
	}
	
	for(auto it1 : like){
		if(!q.empty()){
			ratings[abs(it1.second)] = q.top();
			q.pop();
		}
	}
	
	for(auto it2 : dislike){
		if(!q.empty()){
			ratings[abs(it2.second)] = q.top();
			q.pop();
		}
	}
	
	return ratings;
}

void out(vector<int> &arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	long long t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> ratings;
		
		for(int i=0; i<n; i++){
			int x; cin >> x;
			ratings.push_back(x);
		}
		string review;
		for(int j=0; j<n; j++){
			char ch; cin >> ch;
			review += ch;
		}
		vector<int> permutation = solve(ratings, review);
		
		out(permutation);
	}
	return 0;
}


