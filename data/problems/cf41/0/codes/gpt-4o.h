#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> solve(int &k, int &q, std::vector<int> &a, std::vector<int> &n) {
        std::vector<int> results;
        std::sort(a.begin(), a.end());
        
        // For each n_i in the queries
        for (const int& current_n : n) {
            // Find the number of kickable positions for this n_i
            int max_kickable = std::upper_bound(a.begin(), a.end(), current_n) - a.begin();
            // Calculate how many remain (i.e., winners)
            int winners = current_n - max_kickable;
            results.push_back(winners);
        }
        
        return results;
    }
};


#endif