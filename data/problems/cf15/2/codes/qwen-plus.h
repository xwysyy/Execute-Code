#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        int maxScoreLength = 0;
        int currentProduct = 1;
        int factorial = 1;

        for (int i = 0; i < n; ++i) {
            currentProduct *= a[i];
            factorial *= (i + 1);

            // Adjust the window to ensure the score doesn't decrease
            while (currentProduct > 0 && factorial > 0 && currentProduct / factorial < a[maxScoreLength]) {
                currentProduct /= a[i - maxScoreLength];
                factorial /= (i - maxScoreLength + 1);
                maxScoreLength++;
            }

            // Update the maximum length of subsequence with the highest score
            if (i - maxScoreLength + 1 > result[maxScoreLength - 1]) {
                result[i] = i - maxScoreLength + 1;
            } else {
                result[i] = result[maxScoreLength - 1];
            }
        }

        return result;
    }
};


#endif