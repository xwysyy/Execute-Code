/*

Sure, here's a C++ implementation using dynamic programming to solve the 0/1 Knapsack problem:

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

    // DP table where dp[i][j] represents the maximum value that can be achieved with the first i items and a capacity of j
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i - 1]) {
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
- We use a 2D array `dp` where `dp[i][j]` represents the maximum value that can be achieved using the first `i` items with a knapsack capacity of `j`.
- For each item, we decide whether to include it in the knapsack or not.
- If including the item does not exceed the current capacity `j`, we take the maximum value between including and excluding the item.
- Finally, `dp[N][V]` gives us the maximum value that can be achieved with all `N` items and a knapsack capacity of `V`.

This approach ensures that we consider all possible combinations of items and capacities efficiently within the given constraints.

*/