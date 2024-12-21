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
  - If we do not include the `i-th` item, the value remains `dp[i-1][j]`.
  - If we include the `i-th` item, the value becomes `dp[i-1][j - v[i-1]] + w[i-1]`, provided `j >= v[i-1]`.
- **Result**: The final result is stored in `dp[N][V]`, which is the maximum value achievable with all `N` items and a capacity of `V`.

This code efficiently solves the problem within the given constraints.

*/