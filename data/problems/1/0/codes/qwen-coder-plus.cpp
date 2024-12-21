/*

Here's the C++ code to solve the 0/1 Knapsack problem using dynamic programming:

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
    
    // The maximum value is in dp[N][V]
    cout << dp[N][V] << endl;
    
    return 0;
}

/*

### Explanation:
- We use a 2D DP array `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a knapsack capacity of `j`.
- We iterate through each item and for each capacity from `0` to `V`, we decide whether to include the current item or not.
- If including the item does not exceed the capacity, we take the maximum value between including and excluding the item.
- Finally, `dp[N][V]` gives us the maximum value that can be achieved with all `N` items and a knapsack capacity of `V`.

This approach efficiently solves the problem within the given constraints.

*/