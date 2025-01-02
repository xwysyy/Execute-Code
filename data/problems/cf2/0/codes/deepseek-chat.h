#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            if (s[i] == '>') {
                adj[i].push_back(next);
            } else if (s[i] == '<') {
                adj[next].push_back(i);
            } else if (s[i] == '-') {
                adj[i].push_back(next);
                adj[next].push_back(i);
            }
        }

        // Tarjan's algorithm to find SCCs
        vector<int> disc(n, -1), low(n, -1);
        vector<bool> inStack(n, false);
        stack<int> st;
        int time = 0;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) {
                tarjan(i, adj, disc, low, inStack, st, time, result);
            }
        }

        return result;
    }

private:
    void tarjan(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& inStack, stack<int>& st, int& time, int& result) {
        disc[u] = low[u] = time++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                tarjan(v, adj, disc, low, inStack, st, time, result);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            int cnt = 0;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                cnt++;
                if (v == u) break;
            }
            if (cnt > 1) {
                result += cnt;
            } else if (cnt == 1) {
                // Check if the single node forms a cycle with itself
                for (int v : adj[u]) {
                    if (v == u) {
                        result += 1;
                        break;
                    }
                }
            }
        }
    }
};


#endif