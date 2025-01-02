#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> even, odd;
        for (int num : a) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        vector<int> sortedEven = even;
        vector<int> sortedOdd = odd;
        sort(sortedEven.begin(), sortedEven.end());
        sort(sortedOdd.begin(), sortedOdd.end());
        int evenIdx = 0, oddIdx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                if (evenIdx >= sortedEven.size() || a[i] != sortedEven[evenIdx]) {
                    return "NO";
                }
                evenIdx++;
            } else {
                if (oddIdx >= sortedOdd.size() || a[i] != sortedOdd[oddIdx]) {
                    return "NO";
                }
                oddIdx++;
            }
        }
        return "YES";
    }
};


#endif