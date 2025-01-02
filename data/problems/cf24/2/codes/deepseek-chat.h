#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        sort(a.begin(), a.end());
        int total_cost = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            total_cost += a[right] - a[left];
            left++;
            right--;
        }
        return total_cost;
    }
};


#endif