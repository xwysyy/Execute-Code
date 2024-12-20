/*

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
    
    // DP table: dp[j] represents the maximum value with a capacity of j
    vector<int> dp(V + 1, 0);
    
    // Fill the DP table
    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    // The answer is the maximum value we can achieve with capacity V
    cout << dp[V] << endl;
    
    return 0;
}

/*

This code uses dynamic programming to solve the 0/1 knapsack problem. The `dp` array is used to store the maximum value that can be achieved with each possible capacity from 0 to V. The outer loop iterates over each item, and the inner loop updates the `dp` array in reverse order to ensure that each item is only considered once.

*/