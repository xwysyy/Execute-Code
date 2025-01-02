#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == '.' && s2[i] == '.') {
                string t1 = s1, t2 = s2;
                t1[i] = 'x';
                t2[i] = 'x';
                if (check(n, t1, t2) == 3) {
                    ans++;
                }
            } else if (s1[i] == '.') {
                string t1 = s1, t2 = s2;
                t1[i] = 'x';
                if (check(n, t1, t2) == 3) {
                    ans++;
                }
            } else if (s2[i] == '.') {
                string t1 = s1, t2 = s2;
                t2[i] = 'x';
                if (check(n, t1, t2) == 3) {
                    ans++;
                }
            }
        }
        return ans;
    }

    int check(int n, string s1, string s2) {
        int cnt = 0;
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && s1[j] == '.') || (i == 1 && s2[j] == '.')) {
                    if (!visited[i][j]) {
                        cnt++;
                        dfs(n, s1, s2, i, j, visited);
                    }
                }
            }
        }
        return cnt;
    }

    void dfs(int n, string s1, string s2, int i, int j, vector<vector<bool>> &visited) {
        if (i < 0 || i >= 2 || j < 0 || j >= n || visited[i][j] || (i == 0 && s1[j] == 'x') || (i == 1 && s2[j] == 'x')) {
            return;
        }
        visited[i][j] = true;
        dfs(n, s1, s2, i + 1, j, visited);
        dfs(n, s1, s2, i - 1, j, visited);
        dfs(n, s1, s2, i, j + 1, visited);
        dfs(n, s1, s2, i, j - 1, visited);
    }
};


#endif