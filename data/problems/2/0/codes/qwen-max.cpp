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
    for(int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
    
    // dp[j] represents the maximum value that can be achieved with a capacity of j
    vector<int> dp(V + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    cout << dp[V] << endl;
    return 0;
}

/*

This code uses dynamic programming to solve the 0/1 knapsack problem. The `dp` array is used to store the maximum value that can be achieved for each possible capacity from 0 to V. The outer loop iterates over each item, and the inner loop updates the `dp` array in reverse order to ensure that each item is only considered once.

*/