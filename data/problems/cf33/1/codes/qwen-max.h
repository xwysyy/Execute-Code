#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        sort(a.begin(), a.end());
        
        // Alice's turn: remove at most k elements
        int sum = 0;
        for (int i = 0; i < n - k; ++i) {
            sum += a[i];
        }
        
        // Bob's turn: multiply at most x elements by -1
        priority_queue<int> pq;
        for (int i = 0; i < n - k; ++i) {
            pq.push(a[i]);
            if (pq.size() > x) {
                pq.pop();
            }
        }
        
        // Calculate the final sum after Bob's turn
        while (!pq.empty()) {
            sum -= 2 * pq.top();
            pq.pop();
        }
        
        return sum;
    }
};

#endif