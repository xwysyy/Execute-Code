#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        
        // Calculate the length of consecutive 1's to the left and right for each position
        for (int i = 0, k = 0; i < n; ++i) {
            if (s[i] == '1') {
                k++;
            } else {
                k = 0;
            }
            left[i] = k;
        }
        for (int i = n - 1, k = 0; i >= 0; --i) {
            if (s[i] == '1') {
                k++;
            } else {
                k = 0;
            }
            right[i] = k;
        }
        
        long long maxArea = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') continue;
            
            int height = 1;
            int width = min(left[i], right[i]);
            for (int j = 1; i + j < n && i - j >= 0; ++j) {
                if (s[(i + j) % n] == '0' || s[(i - j + n) % n] == '0') break;
                height++;
                width = min(width, min(left[(i + j) % n], right[(i - j + n) % n]));
                maxArea = max(maxArea, (long long)height * width);
            }
        }
        
        return maxArea;
    }
};

#endif