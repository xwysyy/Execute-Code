#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Separate even and odd numbers into different lists
        vector<int> evens, odds;
        
        for (int num : a) {
            if (num % 2 == 0) {
                evens.push_back(num);
            } else {
                odds.push_back(num);
            }
        }
        
        // Sort each list
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        
        // Reconstruct array and check order
        int even_idx = 0, odd_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                a[i] = evens[even_idx++];
            } else {
                a[i] = odds[odd_idx++];
            }
        }
        
        // Check if the array is sorted
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif