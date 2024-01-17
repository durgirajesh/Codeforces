#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> &info){
	int rounds = info.size(), max_score = INT_MIN;
	unordered_map<string, int> players;
	string winner;
	
	vector<pair<string, int>> det;
	for(int i=0; i<rounds; i++){
		string detail = info[i];
		int j = 0; string player, score;
		bool negative = false;
		
		while(j < detail.length()){
			if(detail[j]>='a' && detail[j]<='z'){
				player += detail[j];
			}else if(detail[j]>='0' && detail[j]<='9'){
				score += detail[j];
			}else if(detail[j] == '-'){
				negative = true;
			}
			j++;
		}
		
		stringstream ss; ss << score;
		int score_ = 0;
		ss >> score_ ;
		
		if(negative){
			score_ = -score_;
		}	
		
		det.push_back(pair<string, int> (player, score_));
		if(players.find(player) != players.end()){
			players[player] += score_;
			
		}else{
			players.insert({player, score_});
		}
	}
	
	for(auto it : players){
		max_score = max(max_score, it.second);
	}
	int cnt = 0;
	for(auto x : players){
		if(x.second == max_score){
			cnt++;
			winner = x.first;
		}
	}

	
	if(cnt == 1){
		return winner;
	}
	
	int _score = 0;
	unordered_map<string, int> mp;
	for(int i=0; i<det.size(); i++){
		if(mp.find(det[i].first) != mp.end()){
			mp[det[i].first] += det[i].second;
			
			if(mp[det[i].first] >= max_score && players[det[i].first] == max_score){
				winner = det[i].first;
				
				break;
			}
		}else {
			mp.insert({det[i].first, det[i].second});
			if(det[i].second >= max_score){
				if(players[det[i].first] == max_score){
					winner = det[i].first;
					
					break;
				}
			}
		}
	}
	
	return winner;
}

int main(){
	int t; cin >> t;
	vector<string> details;
	while(t--){
		string player; int score;
		cin >> player; cin >> score;
		
		string format = player + " " + to_string(score);
		details.push_back(format);
	}
	
	cout << solve(details) << endl;
	return 0;
}


