#include<bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b){
    int costa = n*a, costb = 0;
    while(n > 0){
        if(n == 1){
            costb += a;
            break;
        }

        n -= 2;
        costb += b;
    }

    return min(costa, costb);
}

int main(){
    int t; cin >> t;
    while ( t > 0 ){
        t -= 1;
        int n, a, b;
        cin >> n >> a >> b;

        cout << solve(n, a, b) << endl;
    }
}