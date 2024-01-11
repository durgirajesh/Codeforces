#include<bits/stdc++.h>
using namespace std;

string solve(string Keys){
	string typed;
	stack<int> upper, lower ;
	
	for(int i=0; i<Keys.size(); i++){
		if(Keys[i] == 'b'){
			if(!lower.empty()){
				typed[lower.top()] = '#';
				lower.pop();
			}
			
		}else if(Keys[i] == 'B'){
			if(!upper.empty()){
				typed[upper.top()] = '#';
				upper.pop();
			}
		}else{
			if(isupper(Keys[i])){
				upper.push(i);
			}else if(islower(Keys[i])){
				lower.push(i);
			}
		}
		typed += Keys[i];
	}
	
	string word;
	for(int i=0; i<typed.size(); i++){
		if(typed[i] != '#' && typed[i] != 'b' && typed[i] != 'B'){
			word += typed[i];
		}
	}
	return word;
}


void out(vector<string> arr){
	for(long long i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}
}

int main(){
	long long t; cin >> t;
	while(t--){
		string PressedKeys; cin >> PressedKeys;
		cout << solve(PressedKeys) << endl;
	}
	return 0;
}


