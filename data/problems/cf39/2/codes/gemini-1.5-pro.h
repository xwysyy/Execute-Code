#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        function<bool(int, int)> dfs = [&](int r, int c) {
            if (r == 1 && c == n - 1) return true;
            if (r < 0 || r >= 2 || c < 0 || c >= n || visited[r][c]) return false;
            visited[r][c] = true;
            bool res = false;
            int nr, nc;

            // Move up
            nr = r - 1;
            nc = c;
            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n) {
                if (nr == 0) {
                    nc += (s1[nc] == '>' ? 1 : -1);
                } else {
                    nc += (s2[nc] == '>' ? 1 : -1);
                }
                if (nc >= 0 && nc < n) res |= dfs(nr, nc);
            }


            // Move down
            nr = r + 1;
            nc = c;
            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n) {
                if (nr == 0) {
                    nc += (s1[nc] == '>' ? 1 : -1);
                } else {
                    nc += (s2[nc] == '>' ? 1 : -1);
                }

                if (nc >= 0 && nc < n) res |= dfs(nr, nc);

            }

            // Move left
            nr = r;
            nc = c - 1;

            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n) {
                 if (nr == 0) {
                    nc += (s1[nc] == '>' ? 1 : -1);
                } else {
                    nc += (s2[nc] == '>' ? 1 : -1);
                }
                if (nc >= 0 && nc < n) res |= dfs(nr, nc);
            }


            // Move right
            nr = r;
            nc = c + 1;
            if (nr >= 0 && nr < 2 && nc >= 0 && nc < n) {
                if (nr == 0) {
                    nc += (s1[nc] == '>' ? 1 : -1);
                } else {
                    nc += (s2[nc] == '>' ? 1 : -1);
                }
                if (nc >= 0 && nc < n) res |= dfs(nr, nc);
            }


            return res;
        };
        return dfs(0, 0) ? "YES" : "NO";
    }
};


#endif