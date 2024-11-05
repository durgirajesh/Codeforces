#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int start_up(const vector<pair<int, int>>& nums, int n) {
    unordered_map<int, int> container;
    for (const auto& brand_cost : nums) {
        int brand = brand_cost.first;
        int cost = brand_cost.second;
        container[brand] += cost;
    }

    vector<int> costs;
    for (const auto& entry : container) {
        costs.push_back(entry.second);
    }

    // Sort costs in descending order
    sort(costs.rbegin(), costs.rend());

    // Calculate the maximum sum of the top n costs
    int max_cost = 0;
    for (int i = 0; i < n && i < costs.size(); ++i) {
        max_cost += costs[i];
    }
    return max_cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> bottles;

        for (int i = 0; i < k; ++i) {
            int bi, ci;
            cin >> bi >> ci;
            bottles.emplace_back(bi, ci);
        }

        cout << start_up(bottles, n) << endl;
    }
    return 0;
}
