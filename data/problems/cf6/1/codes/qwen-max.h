#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        int oddCount = 0, evenCount = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        // If all elements are already of the same parity, return "YES"
        if (oddCount == 0 || evenCount == 0) {
            return "YES";
        }
        // If there are both odd and even elements, check if we can make all elements have the same parity
        if (oddCount > 0 && evenCount > 0) {
            // Check if we can make all elements even
            bool canMakeEven = true;
            for (int i = 0; i < n; i += 2) {
                if (a[i] % 2 != 0) {
                    canMakeEven = false;
                    break;
                }
            }
            if (canMakeEven) {
                return "YES";
            }
            // Check if we can make all elements odd
            bool canMakeOdd = true;
            for (int i = 1; i < n; i += 2) {
                if (a[i] % 2 == 0) {
                    canMakeOdd = false;
                    break;
                }
            }
            if (canMakeOdd) {
                return "YES";
            }
        }
        return "NO";
    }
};

#endif