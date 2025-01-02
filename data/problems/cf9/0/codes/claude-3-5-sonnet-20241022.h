#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> result;
        
        // For each query
        for (auto query : queries) {
            int type = query.first;   // 0 for even numbers, 1 for odd numbers
            int x = query.second;     // value to add
            
            // Process each array element
            for (int i = 0; i < n; i++) {
                // If type is 0 and number is even, add x
                // If type is 1 and number is odd, add x
                if ((type == 0 && a[i] % 2 == 0) || 
                    (type == 1 && a[i] % 2 == 1)) {
                    a[i] += x;
                }
            }
            
            // Calculate sum after the query
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }
            result.push_back(sum);
        }
        
        return result;
    }
};


#endif