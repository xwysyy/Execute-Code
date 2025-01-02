#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<int> heights(n, 0); // Heights of the histogram for each column
        long long maxArea = 0;

        // Iterate over each row (cyclic permutation)
        for (int i = 0; i < n; ++i) {

            // Update the histogram for row i
            for (int j = 0; j < n; ++j) {
                if (s[(j - i + n) % n] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Calculate max area in the updated histogram
            stack<int> indices;
            for (int j = 0; j <= n; ++j) {
                while (!indices.empty() && (j == n || heights[j] < heights[indices.top()])) {
                    int h = heights[indices.top()];
                    indices.pop();
                    int width = indices.empty() ? j : j - indices.top() - 1;
                    maxArea = max(maxArea, static_cast<long long>(h * width));
                }
                indices.push(j);
            }
        }
        return maxArea;
    }
};


#endif