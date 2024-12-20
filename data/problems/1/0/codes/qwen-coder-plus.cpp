/*

Here's a C++ implementation of the 0/1 Knapsack problem using dynamic programming:

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

    // Output the maximum value
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D dynamic programming table `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a knapsack capacity of `j`.
- We iterate over each item and for each item, we iterate over all possible capacities from `0` to `V`.
- If the volume of the current item is less than or equal to the current capacity, we decide whether to include the item or not by comparing the value of including it (`dp[i-1][j-v[i-1]] + w[i-1]`) with not including it (`dp[i-1][j]`).
- Finally, the answer will be in `dp[N][V]`, which gives the maximum value achievable with `N` items and a knapsack capacity of `V`.

*/