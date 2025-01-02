#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        sort(a.begin(), a.end());
        int max_value = 0;
        for (int i = 0; i < n; ++i) {
            int target = a[i];
            int left = i, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int count = left - i;
            if (count * 2 > n) {
                max_value = max(max_value, target);
            }
        }
        return max_value;
    }
};

#endif