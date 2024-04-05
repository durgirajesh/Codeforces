#include<bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<int> cards);

int main(){
    int n; 
    cin >> n;
    
    vector<int> cards;
    for(int i=0; i<n; i++){
        int card; cin >> card;
        cards.push_back(card);
    }

    pair<int, int> result = solve(cards);
    cout << result.first << " " << result.second ;
}

pair<int, int> solve(vector<int> cards){
    int turn = 0, sereja_score = 0, dima_score = 0, i = 0, j = cards.size()-1;
        while (i <= j){
            int k = 0;
            if (cards[i] > cards[j]){
                k += cards[i];
                i += 1;
            }else{
                k += cards[j];
                j -= 1;
            }

            if(turn % 2 == 0){
                sereja_score += k;
            }else{
                dima_score += k;
            }
            
            turn += 1;
        }

    return {sereja_score, dima_score};
}