/*

Here is the C++ code to solve the 0/1 Knapsack problem which fits your requirements:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }

    // Initialize a DP array where dp[j] will hold the maximum value for capacity j
    vector<int> dp(V + 1, 0);

    // Process each item
    for (int i = 0; i < N; i++) {
        // Traverse the dp array backward
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The answer is the maximum value we can obtain with full capacity V
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input:** We read the number of items `N` and the max capacity `V` of the backpack. Then for each item, its volume and value.
2. **Dynamic Programming (DP) Array:** We maintain a `dp` vector where `dp[j]` gives the maximum value achievable with weight capacity `j`.
3. **Updating DP Array:** For each item, we traverse the `dp` array backward to ensure that each item can only be selected once.
4. **Output:** Finally, we print the value of `dp[V]`, which holds the maximum value we can achieve within the given capacity. 

This algorithm has a time complexity of O(N * V), which is efficient given the constraints.

*/