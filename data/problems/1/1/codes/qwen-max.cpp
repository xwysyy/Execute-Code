/*

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    
    vector<int> v(N), w(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
    
    // DP table: dp[i][j] represents the maximum value that can be achieved with the first i items and a capacity of j
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= V; ++j) {
            if (v[i-1] > j) {
                // If the current item's volume is more than the current capacity, we cannot include it
                dp[i][j] = dp[i-1][j];
            } else {
                // Otherwise, we take the maximum of including or not including the current item
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1]);
            }
        }
    }
    
    cout << dp[N][V] << endl;
    return 0;
}

/*

This code uses dynamic programming to solve the 0/1 knapsack problem. The `dp` table is used to store the maximum value that can be achieved for each subproblem, where `dp[i][j]` represents the maximum value that can be achieved using the first `i` items with a total capacity of `j`.

*/