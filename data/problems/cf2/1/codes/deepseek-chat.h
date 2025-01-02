#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Build the graph
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

        // Kosaraju's algorithm to find SCCs
        vector<int> order;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, order);
            }
        }

        // Reverse the graph
        vector<vector<int>> reversedAdj(n);
        for (int i = 0; i < n; ++i) {
            for (int j : adj[i]) {
                reversedAdj[j].push_back(i);
            }
        }

        // Find SCCs
        visited.assign(n, false);
        int sccCount = 0;
        for (int i = order.size() - 1; i >= 0; --i) {
            int node = order[i];
            if (!visited[node]) {
                stack<int> stack;
                stack.push(node);
                visited[node] = true;
                while (!stack.empty()) {
                    int current = stack.top();
                    stack.pop();
                    for (int neighbor : reversedAdj[current]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            stack.push(neighbor);
                        }
                    }
                }
                sccCount++;
            }
        }

        // All rooms are returnable if the entire graph is strongly connected
        if (sccCount == 1) {
            return n;
        } else {
            // Otherwise, count the number of nodes in SCCs
            // Since in a circular arrangement with the given constraints, if the graph is not strongly connected,
            // no room is returnable
            return 0;
        }
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, order);
            }
        }
        order.push_back(node);
    }
};


#endif