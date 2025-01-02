#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> evens, odds;
        
        for (int num : a) {
            if (num % 2 == 0) {
                evens.push_back(num);
            } else {
                odds.push_back(num);
            }
        }
        
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        
        int evenIndex = 0, oddIndex = 0;
        
        // Reconstruct a simulated sorted version of the array
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                a[i] = evens[evenIndex++];
            } else {
                a[i] = odds[oddIndex++];
            }
        }
        
        // Check if the array is sorted
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i-1]) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif