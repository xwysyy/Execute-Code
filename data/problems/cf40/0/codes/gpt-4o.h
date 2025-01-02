#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.size();
        
        // Helper function to check for tandem repeat possibility with length 2*k
        auto canBeTandem = [&](int length) -> bool {
            if (length == 0) return true;
            for (int start = 0; start <= n - length; ++start) {
                int k = length / 2;
                bool valid = true;
                for (int i = 0; i < k; ++i) {
                    char first = s[start + i];
                    char second = s[start + i + k];
                    if (first != '?' && second != '?' && first != second) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
            return false;
        };
        
        // Binary search on the length of 2*k
        int left = 0;
        int right = n % 2 == 0 ? n : n - 1;
        int best = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid % 2 != 0) mid--; // ensure it's even
            if (canBeTandem(mid)) {
                best = mid;
                left = mid + 2;
            } else {
                right = mid - 2;
            }
        }
        
        return best;
    }
};


#endif