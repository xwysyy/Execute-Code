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
            // The score is maximized when the subsequence is as long as possible
            // So the cost is the length of the longest subsequence where all elements are equal to the last element
            int last = a[k-1];
            int cost = 0;
            for (int i = k-1; i >= 0; --i) {
                if (a[i] == last) {
                    cost++;
                } else {
                    break;
                }
            }
            result[k-1] = cost;
        }
        return result;
    }
};


#endif