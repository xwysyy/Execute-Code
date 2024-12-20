/*

This problem is a classic example of the 0/1 Knapsack problem. Here's a C++ implementation using dynamic programming:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int V, const vector<int>& v, const vector<int>& w) {
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

    return dp[N][V];
}

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    cout << knapsack(N, V, v, w) << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- We iterate through each item and each possible capacity, updating the `dp` table based on whether including the current item increases the total value without exceeding the capacity.
- Finally, `dp[N][V]` contains the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

This solution runs in \(O(N \times V)\) time and uses \(O(N \times V)\) space, which is efficient given the constraints.

*/