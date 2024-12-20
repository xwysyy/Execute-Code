/*

This problem is a classic example of the 0/1 Knapsack problem. Here is a C++ implementation using dynamic programming:

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

    // DP table where dp[i][j] represents the maximum value we can achieve with first i items and j capacity
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i - 1]) {
                // We can either take the i-th item or not
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                // We cannot take the i-th item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer is the maximum value we can achieve with all N items and full capacity V
    cout << dp[N][V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 2D DP array `dp` where `dp[i][j]` stores the maximum value achievable using the first `i` items with a knapsack capacity of `j`.
- For each item, we decide whether to include it in the knapsack or not based on whether including it would increase the total value without exceeding the capacity.
- Finally, `dp[N][V]` contains the maximum value achievable with all `N` items and a knapsack capacity of `V`.

### Input Format:
The input starts with two integers `N` and `V` representing the number of items and the capacity of the knapsack, respectively. This is followed by `N` lines, each containing two integers `v[i]` and `w[i]` representing the volume and value of the i-th item.

### Output Format:
A single integer representing the maximum value that can be achieved.

*/