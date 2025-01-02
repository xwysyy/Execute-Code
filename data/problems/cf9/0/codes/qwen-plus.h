#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> result;
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        long long evenSum = 0, oddSum = 0;

        // Calculate initial sum of even and odd elements
        for (int num : a) {
            if (num % 2 == 0)
                evenSum += num;
            else
                oddSum += num;
        }

        for (auto query : queries) {
            int type = query.first;
            int value = query.second;

            if (type == 0) { // Add to even elements
                sum += evenSum * ((evenSum > 0) ? 1 : 0);
                evenSum += evenSum * ((evenSum > 0) ? 1 : 0);
                for (int &num : a) {
                    if (num % 2 == 0) {
                        num += value;
                        evenSum += value;
                        sum += value;
                        if (num % 2 != 0) { // If it becomes odd
                            oddSum += num;
                            evenSum -= num;
                        }
                    }
                }
            } else { // Add to odd elements
                sum += oddSum * ((oddSum > 0) ? 1 : 0);
                oddSum += oddSum * ((oddSum > 0) ? 1 : 0);
                for (int &num : a) {
                    if (num % 2 != 0) {
                        num += value;
                        oddSum += value;
                        sum += value;
                        if (num % 2 == 0) { // If it becomes even
                            evenSum += num;
                            oddSum -= num;
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