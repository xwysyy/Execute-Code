/*

Here is the C++ code to solve the 0/1 Knapsack problem:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int V, vector<int>& v, vector<int>& w) {
    // Create a DP table with (N+1) rows and (V+1) columns
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (v[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][V];
}

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    int result = knapsack(N, V, v, w);
    cout << result << endl;

    return 0;
}

/*

### Explanation:
- **Input:** The program reads `N` (number of items) and `V` (backpack capacity). Then it reads the volume `v[i]` and value `w[i]` for each item.
- **DP Table:** `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- **Transition:** For each item, decide whether to include it or not based on whether it fits in the remaining capacity and whether it maximizes the value.
- **Output:** The maximum value that can be achieved with the given constraints is printed.

### Example Input:

/*
3 5
1 2
2 4
3 4

/*

### Example Output:

/*
6

/*

This code efficiently solves the problem within the given constraints.

*/