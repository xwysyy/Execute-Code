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
            // Since the array is non-decreasing, the last element is the largest
            // The score of the subsequence [a_k] is a_k / 1! = a_k
            // The score of any longer subsequence will be less because the factorial in the denominator grows faster than the product in the numerator
            // Therefore, the maximum score is a_k, and the cost is 1
            // However, if there are multiple elements equal to a_k, we can include all of them to maximize the score
            // The cost will be the count of elements equal to a_k in the first k elements
            int max_val = a[k-1];
            int count = 0;
            for (int i = 0; i < k; ++i) {
                if (a[i] == max_val) {
                    ++count;
                }
            }
            result[k-1] = count;
        }
        return result;
    }
};


#endif