/*

To solve this problem, we can use a dynamic programming approach known as the 0/1 Knapsack problem. Here's the C++ code to achieve this:

*/

#include <iostream>
#include <vector>
using namespace std;

int knapSack(int N, int V, const vector<int>& v, const vector<int>& w) {
    // Create a DP table where dp[i][j] represents the maximum value that can be obtained
    // with the first i items and a knapsack capacity of j.
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            // If the current item's volume is more than the current capacity, skip it
            if (v[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Otherwise, consider the maximum value between including the item or not
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }

    // The answer will be in dp[N][V]
    return dp[N][V];
}

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }

    int result = knapSack(N, V, v, w);
    cout << result << endl;

    return 0;
}

/*

### Explanation:
1. **Input Reading**:
   - We read the number of items `N` and the backpack capacity `V`.
   - We then read the volumes `v` and values `w` of each item.

2. **Dynamic Programming Table**:
   - We create a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be obtained using the first `i` items and a knapsack capacity of `j`.

3. **Filling the DP Table**:
   - For each item `i` and each capacity `j`, we have two choices:
     - **Exclude the item**: The value remains the same as `dp[i-1][j]`.
     - **Include the item**: The value is `dp[i-1][j-v[i-1]] + w[i-1]` (if the item fits in the remaining capacity).
   - We take the maximum of these two choices to fill `dp[i][j]`.

4. **Result**:
   - The final answer is stored in `dp[N][V]`, which gives the maximum value that can be achieved with the given constraints.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(N \times V)\), which is efficient given the constraints.

*/