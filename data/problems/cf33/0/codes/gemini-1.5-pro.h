#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(abs(a[i]));
        }
        for (int i = 0; i < k; i++) {
            pq.pop();
        }
        int sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += pq.top();
            pq.pop();
        }

        int neg_count = 0;
        for(int val : a) {
            if(val < 0) neg_count++;
        }

        if(neg_count % 2 == 0) {
            if(x % 2 == 1) {
                sum -= 2 * *min_element(a.begin(), a.end());
            }
        } else {
            
        }



        
        return sum;
    }
};


#endif