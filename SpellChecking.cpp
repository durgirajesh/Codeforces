#include<bits/stdc++.h>
using namespace std;

void out(vector<int>& ans){
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}

vector<int> solve(string a, string b){
    int diff = 0;
    vector<int> ans;

    for(int i = 0, j = 0; i < a.length() && j < b.length();){
        if(a[i] == b[j]){
            i++;
            j++;
        } else {
            diff++;
            ans.push_back(i + 1);
            i++;
        }
    }

    int l = abs(diff - (int)(a.length() - b.length()));
    if(l > 1){
        cout << "0";
        return {};
    }

    return ans;
}

int main(){
    string it1, it2;
    cin >> it1 >> it2;

    vector<int> ans = solve(it1, it2);
    out(ans);

    return 0;
}

