#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &latin){
		
	for (int i = latin.size()-1; i >= 1; i--){
		int l = abs(latin[i] - 26);
		if (latin[i - 1] - l <= 0){
			int y = latin[i-1] - 1;
			latin[i] += y;
			latin[i-1] = 1;
		}
		else{
			latin[i] += l;
			latin[i - 1] -= l;			
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int k = n / 3, p = n % 3;

		vector<int> latin;
		for (int i = 0; i < 3; i++){
			latin.push_back(n / 3);
		}
		
		for (int i = latin.size() - 1; i >= 0; i--){
			int op = abs(latin[i] - 26);
			if (p > 0  && op >= p){
				int q = latin[i];
				latin[i] += p;
				p -= (latin[i] - q);
			}
		}
		
		int w = 2;
		while(w--){
			solve(latin);
		}
		
		
		string alpha;
		for (int i = 0; i < 3; i++){
			alpha += (char)(latin[i] + 96);
		}

		cout << alpha << endl;
	}
}
