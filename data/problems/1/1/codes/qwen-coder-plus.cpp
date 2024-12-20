/*

Certainly! This problem is a classic example of the "0/1 Knapsack Problem" which can be solved using dynamic programming.

Here is the C++ code to solve it:

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

    // dp[i][j] will store the maximum value that can be obtained with the first i items and a backpack capacity of j
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
- We use a 2D array `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- We iterate over each item and each possible capacity of the backpack.
- For each item, we decide whether to include it in the knapsack or not based on whether including it results in a higher value than excluding it.
- Finally, `dp[N][V]` contains the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

This solution has a time complexity of \(O(N \times V)\), which is efficient given the constraints.

*/