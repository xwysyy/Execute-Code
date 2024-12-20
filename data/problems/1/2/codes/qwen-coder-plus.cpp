/*

Sure! This problem is a classic example of the 0/1 Knapsack problem, which can be solved using dynamic programming. Here is the C++ code to solve it:

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
            if (j >= v[i - 1]) {
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
- We use a 2D DP array `dp` where `dp[i][j]` represents the maximum value that can be obtained with the first `i` items and a knapsack capacity of `j`.
- We iterate over each item and for each capacity from 0 to `V`.
- If the current item's volume `v[i-1]` is less than or equal to the current capacity `j`, we have the choice to either include the item or not. We take the maximum of these two choices.
- If the item's volume is greater than the current capacity, we cannot include the item, so the value remains the same as without this item.

This approach ensures that we consider all possible combinations of items and capacities efficiently within the given constraints.

*/