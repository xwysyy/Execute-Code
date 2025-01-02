#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        // Separate the elements into even and odd arrays
        vector<int> evens, odds;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                evens.push_back(a[i]);
            } else {
                odds.push_back(a[i]);
            }
        }

        // Sort even and odd arrays separately
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());

        // Merge sorted even and odd arrays back into original array positions
        int evenIndex = 0, oddIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                a[i] = evens[evenIndex++];
            } else {
                a[i] = odds[oddIndex++];
            }
        }

        // Check if the merged array is sorted in non-decreasing order
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                return "NO";
            }
        }

        return "YES";
    }
};


#endif