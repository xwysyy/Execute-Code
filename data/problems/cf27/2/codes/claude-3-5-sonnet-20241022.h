#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Create separate vectors for even and odd numbers
        vector<int> even, odd;
        vector<int> evenPos, oddPos;
        
        // Separate numbers by parity and keep track of their positions
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
                evenPos.push_back(i);
            } else {
                odd.push_back(a[i]);
                oddPos.push_back(i);
            }
        }
        
        // Sort the even and odd numbers separately
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        // Create the expected sorted array
        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());
        
        // Create the array we would get after sorting even and odd numbers separately
        vector<int> result = a;
        for (int i = 0; i < even.size(); i++) {
            result[evenPos[i]] = even[i];
        }
        for (int i = 0; i < odd.size(); i++) {
            result[oddPos[i]] = odd[i];
        }
        
        // Check if the result matches the expected sorted array
        return (result == sorted) ? "YES" : "NO";
    }
};


#endif