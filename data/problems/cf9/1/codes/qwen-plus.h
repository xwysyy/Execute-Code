#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> result;
        long long sum = accumulate(a.begin(), a.end(), 0LL); // Calculate initial sum

        for (auto &query : queries) {
            int type = query.first;
            int value = query.second;
            long long evenCount = 0, oddCount = 0;

            // Count the number of even and odd elements
            for (int i = 0; i < n; ++i) {
                if (a[i] % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }

            if (type == 0) { // Add value to all even elements
                sum += evenCount * value;
                for (int i = 0; i < n; ++i) {
                    if (a[i] % 2 == 0)
                        a[i] += value;
                }
            } else { // Add value to all odd elements
                sum += oddCount * value;
                for (int i = 0; i < n; ++i) {
                    if (a[i] % 2 != 0)
                        a[i] += value;
                }
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};


#endif