/*

Here is the C++ code to solve the 0/1 Knapsack problem:

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    
    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
    
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

### Explanation:
- **Input**: The first line contains `N` (number of items) and `V` (backpack capacity). The next `N` lines contain the volume `v[i]` and value `w[i]` of each item.
- **Dynamic Programming Array `dp`**: `dp[j]` represents the maximum value that can be achieved with a backpack capacity of `j`.
- **Nested Loop**: The outer loop iterates over each item, and the inner loop iterates over the capacity from `V` down to `v[i]` to ensure each item is used at most once.
- **Transition**: `dp[j] = max(dp[j], dp[j - v[i]] + w[i])` updates the maximum value by either including or excluding the current item.
- **Output**: The final result is `dp[V]`, which is the maximum value achievable with the given capacity.

This code efficiently solves the problem within the given constraints.

*/