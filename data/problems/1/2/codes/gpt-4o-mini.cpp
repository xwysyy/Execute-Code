/*

Here is the C++ code to solve the 0/1 Knapsack problem based on the provided constraints:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N + 1), w(N + 1); // volumes and weights
    for (int i = 1; i <= N; ++i) {
        cin >> v[i] >> w[i];
    }

    // Create a DP array to store maximum value for each capacity
    vector<int> dp(V + 1, 0);

    // Process each item
    for (int i = 1; i <= N; ++i) {
        // Iterate capacities backward to ensure we are using each item only once
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The result is the maximum value obtainable with the full capacity V
    cout << dp[V] << endl;

    return 0;
}

/*

In this code:
- We read the number of items `N` and the capacity `V` of the backpack.
- We read the volume and value of each item into vectors `v` and `w`.
- We create a dynamic programming array `dp` to store the maximum values for each possible capacity up to `V`.
- We fill the `dp` array using the bottom-up approach and finally output the maximum value that can be carried in the backpack.

*/