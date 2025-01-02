#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        for (int k = 1; k <= n; ++k) {
            // The maximum score is achieved by the subsequence with the largest elements
            // Since the array is non-decreasing, the largest elements are at the end
            // The cost is the length of the longest subsequence with the largest elements
            // Since the array is non-decreasing, the longest subsequence with the largest elements is the entire sequence
            // However, the score is maximized when the subsequence consists of the largest elements
            // So, the cost is the number of largest elements in the first k elements
            // Since the array is non-decreasing, the largest element in the first k elements is a[k-1]
            // The cost is the count of a[k-1] in the first k elements
            int max_val = a[k-1];
            int count = 0;
            for (int i = 0; i < k; ++i) {
                if (a[i] == max_val) {
                    count++;
                }
            }
            result[k-1] = count;
        }
        return result;
    }
};


#endif