/*

Here is a C++ implementation for solving the 0/1 Knapsack problem given the constraints you described:

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

    // DP array
    vector<int> dp(V + 1, 0);

    // Process each item
    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value achievable with the given capacity V
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
- The program first reads the number of items `N` and the backpack capacity `V`.
- Then, it initializes vectors to hold the volumes and values of the items.
- A dynamic programming array `dp` is used to keep track of the maximum values achievable for each possible volume from `0` to `V`.
- The nested loop iterates over items and updates the `dp` array from the back to avoid using the same item multiple times.
- Finally, it outputs the maximum value that can be achieved without exceeding the backpack capacity.

*/