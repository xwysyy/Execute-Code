#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int count = 0;
        long long sum = 0;
        int start = 0;
        
        for (int end = 0; end < n; ++end) {
            sum += a[end];
            while (sum > r && start <= end) {
                sum -= a[start];
                start++;
            }
            if (sum >= l && sum <= r) {
                count++;
                sum = 0;
                start = end + 1;
            }
        }
        
        return count;
    }
};


#endif