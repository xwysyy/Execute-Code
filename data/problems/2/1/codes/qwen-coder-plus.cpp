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
- **Input Reading**: We read the number of items `N` and the capacity of the backpack `V`. Then we read the volume and weight of each item.
- **DP Table Initialization**: We create a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- **DP Table Filling**: We iterate over each item and each possible capacity of the backpack. For each item, we decide whether to include it in the knapsack or not based on whether including it results in a higher value than excluding it.
- **Result**: The maximum value that can be achieved with all `N` items and a backpack capacity of `V` is stored in `dp[N][V]`.

This solution efficiently computes the result within the given constraints.

*/