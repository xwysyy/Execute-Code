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
            int nr = r, nc = c;
            if (r == 0) {
                if (s1[c] == '>') nc++;
                else nc--;
            } else {
                if (s2[c] == '>') nc++;
                else nc--;
            }
            if (nc >= 0 && nc < n) {
                 if (dfs(nr, nc)) return true;
            }
           
            nr = r -1;
             nc = c;
            if (nr >= 0 && nr < 2) {
                   if (r == 0) {
                        if (s1[c] == '>') nc++;
                        else nc--;
                    } else {
                        if (s2[c] == '>') nc++;
                        else nc--;
                    }
                    if (nc >= 0 && nc < n)
                     if (dfs(nr, nc)) return true;
            }

            nr = r + 1;
             nc = c;
            if (nr >= 0 && nr < 2) {
                   if (r == 0) {
                        if (s1[c] == '>') nc++;
                        else nc--;
                    } else {
                        if (s2[c] == '>') nc++;
                        else nc--;
                    }
                      if (nc >= 0 && nc < n)
                       if (dfs(nr, nc)) return true;
            }
             
             
           return false;
        };
        return dfs(0, 0) ? "YES" : "NO";
    }
};


#endif