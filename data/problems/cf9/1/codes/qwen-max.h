#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        long long sum = 0;
        long long evenSum = 0;
        long long oddSum = 0;
        int evenCount = 0;
        int oddCount = 0;
        
        // Calculate initial sums and counts
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] % 2 == 0) {
                evenSum += a[i];
                evenCount++;
            } else {
                oddSum += a[i];
                oddCount++;
            }
        }
        
        vector<long long> result;
        
        // Process each query
        for (auto &query : queries) {
            int type = query.first;
            int value = query.second;
            
            if (type == 0) { // Add to even elements
                evenSum += (long long)evenCount * value;
            } else { // Add to odd elements
                oddSum += (long long)oddCount * value;
            }
            
            sum = evenSum + oddSum;
            result.push_back(sum);
        }
        
        return result;
    }
};

#endif