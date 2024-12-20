/*

Here is the C++ code to solve the 0/1 knapsack problem based on the provided specifications:

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

    // DP Array to store maximum value for each volume
    vector<int> dp(V + 1, 0);

    // 0/1 Knapsack DP approach
    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value that can be obtained
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input Handling**:
   - Read the number of items `N` and the capacity of the backpack `V`.
   - Create two vectors to store the volumes and values of the items.

2. **Dynamic Programming Setup**:
   - Initialize a DP array `dp` to hold the maximum values for every possible capacity from `0` to `V`.

3. **0/1 Knapsack Logic**:
   - For each item, iterate backwards through the DP array and update it with the maximum value that can be achieved when considering that item.

4. **Output**:
   - The maximum value obtainable with the capacity of the backpack `V` is stored in `dp[V]`, which is printed as the result.

This code efficiently calculates the maximum value while adhering to the constraints provided. The size of `N` and `V` means this solution will execute well within the time limits.

*/