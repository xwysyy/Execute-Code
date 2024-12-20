/*

This problem is a classic example of the 0/1 Knapsack problem, which can be solved using dynamic programming. Below is a C++ implementation for the given constraints:

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

    // DP array to store the maximum value for each volume up to V
    vector<int> dp(V + 1, 0);

    // Iterate over each item
    for (int i = 0; i < N; ++i) {
        // Update the DP array from back to front to avoid overwriting values needed in the same iteration
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The answer is the maximum value we can achieve with volume up to V
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
- We use a 1D DP array `dp` where `dp[j]` represents the maximum value achievable with a knapsack capacity of `j`.
- For each item, we iterate backwards through the DP array to update the maximum value that can be achieved for each possible volume.
- This backward iteration ensures that each item is only considered once per capacity, adhering to the 0/1 Knapsack constraint.
- Finally, `dp[V]` will contain the maximum value that can be achieved with the full capacity `V`.

This solution runs efficiently within the given constraints.

*/