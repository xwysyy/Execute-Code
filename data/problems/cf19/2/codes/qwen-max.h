#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        
        // Calculate the next occurrence of '0' to the left for each position
        for (int i = 0, j = -1; i < n; ++i) {
            if (s[i] == '0') j = i;
            left[i] = j;
        }
        
        // Calculate the next occurrence of '0' to the right for each position
        for (int i = n - 1, j = n; i >= 0; --i) {
            if (s[i] == '0') j = i;
            right[i] = j;
        }
        
        long long maxArea = 0;
        for (int k = 0; k < n; ++k) {
            int l = left[k], r = right[k];
            if (l == -1) l = 0;
            else l = (l + 1) % n;
            if (r == n) r = n - 1;
            else r = (r - 1 + n) % n;
            
            int width = (r - l + n) % n;
            long long area = (long long)width * (n - k);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};

#endif