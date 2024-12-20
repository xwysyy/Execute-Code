/*

Here is the C++ code to solve the 0/1 Knapsack problem:

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // Number of items
    int V; // Capacity of the backpack
    cin >> N >> V;

    vector<int> v(N); // Volumes
    vector<int> w(N); // Values

    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i]; // Input for volumes and values
    }

    // DP array for storing maximum values for each capacity
    vector<int> dp(V + 1, 0);

    // 0/1 Knapsack DP approach
    for (int i = 0; i < N; i++) {
        // Traverse backwards to prevent overwriting
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value that can be achieved within the capacity
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input Handling:** First, we read the number of items `N` and the capacity `V` of the backpack. Then, we read the volumes and values of the items.
2. **Dynamic Programming Array (`dp`):** We define a DP array `dp` where `dp[j]` represents the maximum value that can be achieved with a backpack capacity `j`.
3. **Filling the DP Array:** We iterate through each item and update the `dp` array from back to front to avoid using the same item more than once.
4. **Output:** Finally, we print the maximum value that can be achieved with the given capacity.

### Constraints:
- Make sure the inputs are within the constraints \( 0 < N, V, v[i], w[i] \leq 10 \). The provided code efficiently handles those constraints.

*/