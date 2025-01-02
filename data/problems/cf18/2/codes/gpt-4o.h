#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        std::sort(a.begin(), a.end());
        
        long long min_cost = LLONG_MAX;
        
        // Calculate cost for each possible size of the permutation
        long long deletions = 0;
        std::set<int> seen;
        
        for (int i = 0; i <= n; ++i) {
            long long missing = 0;
            if (i > 0) {
                if (a[i - 1] > i && seen.find(i) == seen.end()) {
                    seen.insert(a[i - 1]);
                }
                if (a[i - 1] > i) {
                    deletions += c;
                } else {
                    missing += (i - a[i - 1]) * d;
                }
            }
            
            long long current_cost = deletions + (i * d) - missing;
            min_cost = std::min(min_cost, current_cost);
            
            if (i < n && a[i] > i + 1 && seen.find(i + 1) == seen.end()) {
                seen.insert(i + 1);
            }
        }
        
        return min_cost;
    }
};


#endif