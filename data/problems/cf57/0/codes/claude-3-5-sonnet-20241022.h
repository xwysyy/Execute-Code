#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Group bottles by brand and sort by cost
        map<int, vector<int>> brandGroups;
        for (int i = 0; i < k; i++) {
            brandGroups[b[i].first].push_back(b[i].second);
        }
        
        // Sort costs for each brand in descending order
        vector<int> brandSums;
        for (auto &group : brandGroups) {
            sort(group.second.begin(), group.second.end(), greater<int>());
            // Calculate cumulative sum for each brand
            int sum = 0;
            for (int cost : group.second) {
                sum += cost;
            }
            brandSums.push_back(sum);
        }
        
        // Sort brand sums in descending order
        sort(brandSums.begin(), brandSums.end(), greater<int>());
        
        // Take the sum of top n brands (or all if n > number of brands)
        int result = 0;
        for (int i = 0; i < min(n, (int)brandSums.size()); i++) {
            result += brandSums[i];
        }
        
        return result;
    }
};


#endif