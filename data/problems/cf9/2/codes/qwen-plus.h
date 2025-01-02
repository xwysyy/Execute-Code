#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> result;
        long long sum = 0;
        long long evenCount = 0;
        long long oddCount = 0;

        // Calculate initial sums and counts
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (a[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        // Process each query
        for (auto &query : queries) {
            int type = query.first;
            int value = query.second;

            if (type == 0) { // Add value to all even elements
                sum += evenCount * value;
                // Update counts based on whether adding value changes parity
                for (int &num : a) {
                    if (num % 2 == 0) {
                        num += value;
                        if (num % 2 != 0) {
                            evenCount--;
                            oddCount++;
                        }
                    }
                }
            } else { // Add value to all odd elements
                sum += oddCount * value;
                // Update counts based on whether adding value changes parity
                for (int &num : a) {
                    if (num % 2 != 0) {
                        num += value;
                        if (num % 2 == 0) {
                            oddCount--;
                            evenCount++;
                        }
                    }
                }
            }
            result.push_back(sum);
        }

        return result;
    }
};


#endif