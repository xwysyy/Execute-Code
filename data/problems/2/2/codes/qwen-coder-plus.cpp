/*

This problem is a classic example of the 0/1 Knapsack problem, which can be solved using dynamic programming. Here's the C++ code to solve it:

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
    
    // dp[i][j] will be the maximum value that can be achieved with first i items and j capacity
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[N][V] << endl;
    
    return 0;
}

/*

### Explanation:
- **Input Reading**: The program reads the number of items `N` and the capacity of the backpack `V`. Then, it reads the volume and value for each item.
- **Dynamic Programming Table Initialization**: A 2D vector `dp` is initialized where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`.
- **Filling the DP Table**: For each item, the program iterates through all possible capacities from `0` to `V`. If the current item's volume can fit into the current capacity `j`, it decides whether to include the item or not by comparing the value of including the item (`dp[i-1][j-v[i-1]] + w[i-1]`) with the value of excluding the item (`dp[i-1][j]`). Otherwise, it simply carries forward the value from the previous item (`dp[i-1][j]`).
- **Result Output**: Finally, the program outputs the maximum value that can be achieved with all `N` items and a backpack capacity of `V`, which is stored in `dp[N][V]`.

*/