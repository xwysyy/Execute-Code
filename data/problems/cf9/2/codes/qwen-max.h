#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        long long sum = 0;
        long long evenSum = 0, oddSum = 0;
        int evenCount = 0, oddCount = 0;
        
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
        
        vector<long long> results;
        
        for (auto &query : queries) {
            int type = query.first;
            int value = query.second;
            
            if (type == 0) { // Add to even elements
                evenSum += (long long)value * evenCount;
                sum += (long long)value * evenCount;
            } else { // Add to odd elements
                oddSum += (long long)value * oddCount;
                sum += (long long)value * oddCount;
            }
            
            // Update the count of even and odd elements
            if (value % 2 != 0) {
                if (type == 0) {
                    int temp = evenCount;
                    evenCount = oddCount;
                    oddCount = temp;
                } else {
                    int temp = oddCount;
                    oddCount = evenCount;
                    evenCount = temp;
                }
            }
            
            results.push_back(sum);
        }
        
        return results;
    }
};

#endif