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
- `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- The outer loop iterates over each item.
- The inner loop iterates over each possible capacity from `0` to `V`.
- If the current capacity `j` is greater than or equal to the volume of the current item `v[i-1]`, we consider whether to include the item or not.
- We take the maximum of either including the item or not including it.
- Finally, `dp[N][V]` gives the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

*/