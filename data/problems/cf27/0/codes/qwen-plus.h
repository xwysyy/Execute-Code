#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        // Separate the elements into even and odd arrays
        vector<int> even, odd;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }

        // Sort the even and odd arrays separately
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        // Reconstruct the array with sorted even and odd elements
        int e = 0, o = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                a[i] = even[e++];
            } else {
                a[i] = odd[o++];
            }
        }

        // Check if the reconstructed array is sorted in non-decreasing order
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                return "NO";
            }
        }

        return "YES";
    }
};


#endif