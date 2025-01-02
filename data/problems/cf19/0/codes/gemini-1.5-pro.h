#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(string &s) {
        int n = s.length();
        vector<vector<int>> table(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(j - i + n) % n] - '0';
            }
        }

        long long max_area = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> heights(n, 0);
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (table[j][k] == 1) {
                        heights[k]++;
                    } else {
                        heights[k] = 0;
                    }
                }

                for (int k = 0; k < n; ++k) {
                    int min_height = heights[k];
                    for (int l = k; l < n; ++l) {
                        min_height = min(min_height, heights[l]);
                        if (min_height > 0) {
                            max_area = max(max_area, (long long)min_height * (l - k + 1) * (j - i + 1));
                        } else {
                            break;
                        }
                    }
                }

            }
        }
        return max_area;
    }
};


#endif