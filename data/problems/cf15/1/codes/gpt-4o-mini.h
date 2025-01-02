#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> answer(n);
        unordered_map<int, int> count;
        int max_length = 0;

        for (int i = 0; i < n; ++i) {
            count[a[i]]++; // Count the occurrence of a[i]
            max_length = max(max_length, count[a[i]]); // Update the maximum length found
            answer[i] = max_length; // Save the current max length in the answer
        }

        return answer;
    }
};


#endif