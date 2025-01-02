#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Alice will remove the smallest k elements to maximize the sum
        sort(a.begin(), a.end());
        for (int i = 0; i < k && i < n; ++i) {
            a[i] = 0; // Removing the smallest elements by setting them to 0
        }
        
        // Bob will flip the largest x elements to minimize the sum
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < x && i < n; ++i) {
            a[i] = -a[i]; // Flipping the largest elements
        }
        
        // Calculate the sum of the array
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        
        return sum;
    }
};


#endif