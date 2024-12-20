/*

Here is the C++ code to solve the 0/1 Knapsack problem:

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

    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }

    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- **Input Reading**: The first line reads `N` (number of items) and `V` (backpack capacity). The next `N` lines read the volume `v[i]` and value `w[i]` of each item.
- **Dynamic Programming Table**: `dp[i][j]` represents the maximum value that can be achieved using the first `i` items and a backpack capacity of `j`.
- **DP Transition**:
  - If the current capacity `j` is less than the volume of the `i-th` item, we cannot include it, so `dp[i][j] = dp[i-1][j]`.
  - Otherwise, we have two choices: either include the `i-th` item or not. We take the maximum of these two choices: `dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1])`.
- **Output**: The final result is stored in `dp[N][V]`, which is the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(N \times V)\), which is efficient given the constraints \(0 < N, V, v[i], w[i] \leq 10\).

*/