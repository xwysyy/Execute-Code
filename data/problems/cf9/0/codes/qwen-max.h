#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        long long sum = 0;
        long long even_sum = 0;
        long long odd_sum = 0;
        int even_count = 0;
        int odd_count = 0;
        
        // Calculate initial sums and counts
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even_sum += a[i];
                even_count++;
            } else {
                odd_sum += a[i];
                odd_count++;
            }
            sum += a[i];
        }
        
        vector<long long> result;
        
        for (auto &query : queries) {
            int type = query.first;
            int value = query.second;
            
            if (type == 0) { // Add to even elements
                even_sum += (long long)value * even_count;
            } else { // Add to odd elements
                odd_sum += (long long)value * odd_count;
            }
            
            sum = even_sum + odd_sum;
            result.push_back(sum);
        }
        
        return result;
    }
};

#endif