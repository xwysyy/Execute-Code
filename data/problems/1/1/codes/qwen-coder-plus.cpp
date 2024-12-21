/*

Certainly! This problem is a classic example of the 0/1 Knapsack problem, which can be solved using dynamic programming. Here's the C++ code to solve it:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // DP table: dp[i][j] means the maximum value we can get with the first i items and a capacity of j
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer is the maximum value we can get with all N items and a capacity of V
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D DP table `dp` where `dp[i][j]` represents the maximum value we can achieve with the first `i` items and a backpack capacity of `j`.
- For each item, we decide whether to include it in the knapsack or not based on whether including it increases the total value without exceeding the capacity.
- The final answer is found at `dp[N][V]`, which gives the maximum value achievable with all `N` items and a backpack capacity of `V`.

This solution efficiently computes the result within the given constraints.

*/