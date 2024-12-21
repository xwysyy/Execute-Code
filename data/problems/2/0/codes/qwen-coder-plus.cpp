/*

Here is a C++ implementation using dynamic programming to solve the 0/1 Knapsack problem:

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

    // The answer is in dp[N][V]
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- **Input Reading**: We read the number of items `N` and the maximum volume `V` of the backpack. Then we read the volume and weight of each item.
- **Dynamic Programming Table (`dp`)**: `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- **Initialization**: The table is initialized to zero.
- **Filling the DP Table**:
  - For each item `i` from 1 to `N`, and for each possible volume `j` from 0 to `V`:
    - If the volume of the current item `v[i-1]` is less than or equal to `j`, we have the option to include it in the knapsack. We take the maximum value between including the item (`dp[i-1][j-v[i-1]] + w[i-1]`) and excluding it (`dp[i-1][j]`).
    - If the volume of the current item is greater than `j`, we cannot include it, so `dp[i][j] = dp[i-1][j]`.
- **Result**: The maximum value that can be achieved with all items and the full capacity `V` is stored in `dp[N][V]`.

This solution efficiently computes the result within the given constraints.

*/