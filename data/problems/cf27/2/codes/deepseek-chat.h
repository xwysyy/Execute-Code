#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Create a sorted version of the array
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        
        // Check if the parity of each element matches in the original and sorted array
        for (int i = 0; i < n; i++) {
            if ((a[i] % 2) != (sorted_a[i] % 2)) {
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif