/*

To solve this problem, we can use dynamic programming. Specifically, we will use a 1D DP array to keep track of the maximum value that can be achieved for each possible volume up to the capacity of the backpack.

Here is the C++ code to solve the problem:

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

    // DP array to store the maximum value for each volume
    vector<int> dp(V + 1, 0);

    // Iterate over each item
    for (int i = 0; i < N; ++i) {
        // Update the DP array in reverse order to avoid using the same item multiple times
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value that can be achieved with the given capacity
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input Reading:**
   - Read the number of items `N` and the capacity of the backpack `V`.
   - Read the volumes `v[i]` and values `w[i]` of each item.

2. **DP Array Initialization:**
   - Initialize a DP array `dp` of size `V + 1` with all elements set to 0. `dp[j]` will store the maximum value that can be achieved with a total volume of `j`.

3. **DP Table Update:**
   - For each item, update the DP array in reverse order to ensure that each item is used at most once.
   - For each possible volume `j` from `V` down to `v[i]`, update `dp[j]` to be the maximum of its current value and the value obtained by including the current item.

4. **Output:**
   - The final answer is stored in `dp[V]`, which represents the maximum value that can be achieved with the given capacity `V`.

This approach ensures that the solution is computed efficiently within the given constraints.

*/