/*

Here's a C++ implementation using dynamic programming to solve the 0/1 Knapsack problem:

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N);
    vector<int> w(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // dp[i][j] will store the maximum value that can be obtained with first i items and capacity j
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (v[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved using the first `i` items with a backpack capacity of `j`.
- We iterate over each item and for each capacity from `0` to `V`.
- If the current item's volume `v[i-1]` is less than or equal to the current capacity `j`, we have two choices:
  - Do not include the item: `dp[i][j] = dp[i-1][j]`
  - Include the item: `dp[i][j] = dp[i-1][j-v[i-1]] + w[i-1]`
- We take the maximum of these two choices.
- Finally, `dp[N][V]` gives us the maximum value that can be achieved with `N` items and a backpack capacity of `V`.

This approach ensures that we efficiently compute the solution within the given constraints.

*/