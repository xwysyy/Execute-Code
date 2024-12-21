/*

Certainly! This problem is a classic example of the "0/1 Knapsack Problem," which can be solved using dynamic programming. Below is a C++ implementation that solves the problem within the given constraints:

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // Initialize DP table
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

    // The maximum value that can be achieved is in dp[N][V]
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved using the first `i` items with a backpack capacity of `j`.
- We iterate through each item and for each possible capacity from `0` to `V`.
- If the current item's volume `v[i-1]` is less than or equal to the current capacity `j`, we have two choices:
  - Include the item and add its value to the maximum value achievable with the remaining capacity (`j - v[i-1]`).
  - Exclude the item and carry forward the maximum value achievable without it.
- We take the maximum of these two choices.
- Finally, `dp[N][V]` gives us the maximum value that can be achieved with `N` items and a backpack capacity of `V`.

This solution efficiently computes the result within the given constraints.

*/