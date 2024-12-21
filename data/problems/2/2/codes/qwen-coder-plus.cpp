/*

This problem is a classic example of the 0/1 Knapsack problem, which can be solved using dynamic programming. Below is the C++ code to solve it:

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
    
    // The maximum value that can be achieved
    cout << dp[N][V] << endl;
    
    return 0;
}

/*

### Explanation:
1. **Input Reading**: We read the number of items `N` and the capacity of the backpack `V`. Then, we read the volume and value of each item.
2. **DP Table Initialization**: We initialize a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
3. **DP Table Filling**: We iterate over each item and each possible capacity. If the current item can fit in the backpack (i.e., `j >= v[i-1]`), we decide whether to include it or not by taking the maximum of including it (`dp[i-1][j-v[i-1]] + w[i-1]`) or excluding it (`dp[i-1][j]`). If it cannot fit, we simply carry forward the previous maximum value (`dp[i-1][j]`).
4. **Result Output**: The maximum value that can be achieved with all items and the given backpack capacity is stored in `dp[N][V]`.

This solution efficiently solves the problem within the given constraints.

*/