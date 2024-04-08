#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ship_war(vector<int> &nums, int k){
    int i = 0, j = nums.size()-1, sunk = 0, turn = 0;
    while( k > 0 && i <= j){
        if(turn % 2 == 0){
            nums[i] -= 1;
            if(nums[i] == 0){
                sunk++;
                i++;
            }
        }else{
            nums[j] -= 1;
            if(nums[j] == 0){
                sunk++;
                j--;
            }
        }

        turn += 1;
        k--;
    }

    return sunk;
}

int main(){
	ll t; cin >> t;
	while(t--){
		int n, k;
        cin >> n >> k;

        vector<int> durability;
        int i = 0;
        
        for( ; i < n; i++){
            int ai; cin >> ai;
            durability.push_back(ai);
        }

        cout << ship_war(durability, k) << endl;
	}
	return 0;
}


