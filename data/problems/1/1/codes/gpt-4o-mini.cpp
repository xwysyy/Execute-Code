/*

Here is a C++ code to solve the knapsack problem as described:

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

    // DP array to store maximum values for each capacity
    vector<int> dp(V + 1, 0);

    // Process each item
    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value that can be achieved is in dp[V]
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. **Input Reading**: The first line reads the number of items \( N \) and the backpack capacity \( V \). The next \( N \) lines read the volume and value of each item.
2. **Dynamic Programming Array**: A `dp` array of size \( V + 1 \) is initialized to store the maximum value achievable for each capacity from `0` to `V`.
3. **Knapsack Logic**: For each item, the algorithm checks from the backpack's maximum capacity \( V \) down to the volume of the current item. It updates the `dp` value to the maximum of either taking the item or not.
4. **Output**: Finally, it outputs the maximum value that can be achieved, which is stored in `dp[V]`.

### Note:
This code works efficiently under the given constraints (each \( N \) and \( V \) is at most 10), making it computationally feasible. The time complexity is \( O(N \cdot V) \).

*/