#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort array b to easily access max/min values
        sort(b.begin(), b.end());
        
        // For each position, calculate difference with both smallest and largest
        // available values from b
        vector<pair<long long, int>> diffs(n);  // {difference, index}
        
        for (int i = 0; i < n; i++) {
            long long diff1 = abs(1LL * a[i] - b[0]);        // with smallest
            long long diff2 = abs(1LL * a[i] - b[m-1]);      // with largest
            diffs[i] = {max(diff1, diff2), i};
        }
        
        // Sort differences in descending order to process largest differences first
        sort(diffs.rbegin(), diffs.rend());
        
        long long result = 0;
        vector<bool> used_left(n, false), used_right(n, false);
        int left = 0, right = m-1;
        
        // Process each position
        for (int i = 0; i < n; i++) {
            int idx = diffs[i].second;
            long long diff1 = abs(1LL * a[idx] - b[left]);
            long long diff2 = abs(1LL * a[idx] - b[right]);
            
            // Choose the value that gives larger difference
            if (diff1 > diff2) {
                result += diff1;
                left++;
            } else {
                result += diff2;
                right--;
            }
        }
        
        return result;
    }
};


#endif