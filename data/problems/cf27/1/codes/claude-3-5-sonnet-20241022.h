#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Create separate vectors for odd and even numbers
        vector<int> odd, even;
        vector<int> odd_pos, even_pos;
        
        // Separate odd and even numbers while keeping track of their positions
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
                even_pos.push_back(i);
            } else {
                odd.push_back(a[i]);
                odd_pos.push_back(i);
            }
        }
        
        // Sort the odd and even numbers
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        // Create the expected sorted array
        vector<int> sorted = a;
        
        // Put back sorted odd numbers
        for (int i = 0; i < odd.size(); i++) {
            sorted[odd_pos[i]] = odd[i];
        }
        
        // Put back sorted even numbers
        for (int i = 0; i < even.size(); i++) {
            sorted[even_pos[i]] = even[i];
        }
        
        // Check if the array is sorted
        for (int i = 1; i < n; i++) {
            if (sorted[i] < sorted[i-1]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif