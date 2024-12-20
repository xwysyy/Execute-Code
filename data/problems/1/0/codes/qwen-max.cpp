/*

To solve this problem, we can use a dynamic programming approach. The idea is to use a 2D array `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.

Here's the C++ code to solve the problem:

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

    // Initialize the dp table
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (v[i - 1] > j) {
                // If the current item cannot fit in the remaining capacity, skip it
                dp[i][j] = dp[i - 1][j];
            } else {
                // Otherwise, take the maximum of including or excluding the current item
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }

    // The answer is the maximum value for the full capacity
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input Reading:**
   - Read the number of items `N` and the backpack capacity `V`.
   - Read the volume and value of each item.

2. **DP Table Initialization:**
   - Create a 2D vector `dp` of size `(N+1) x (V+1)` initialized to 0. `dp[i][j]` will store the maximum value that can be obtained using the first `i` items with a capacity of `j`.

3. **Filling the DP Table:**
   - For each item `i` from 1 to `N`:
     - For each capacity `j` from 0 to `V`:
       - If the current item's volume `v[i-1]` is greater than the current capacity `j`, then the item cannot be included, so `dp[i][j] = dp[i-1][j]`.
       - Otherwise, the maximum value can be either by excluding the item (`dp[i-1][j]`) or by including the item (`dp[i-1][j - v[i-1]] + w[i-1]`). We take the maximum of these two values.

4. **Output:**
   - The result is stored in `dp[N][V]`, which represents the maximum value that can be achieved with all `N` items and a capacity of `V`.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(N \times V)\), which is efficient given the constraints.

*/