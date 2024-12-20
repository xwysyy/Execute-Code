/*

Here is a C++ implementation using dynamic programming to solve the 0/1 Knapsack problem:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N);
    vector<int> w(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // Initialize the DP table
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

    // The answer is in dp[N][V]
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D DP table `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- For each item, we decide whether to include it in the knapsack or not.
- If the volume of the current item is less than or equal to the current capacity `j`, we have two choices:
  - Include the item and add its value to the maximum value achievable with the remaining capacity (`j - v[i-1]`).
  - Exclude the item and carry forward the maximum value achievable without it.
- The final result is stored in `dp[N][V]`, which gives the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

*/