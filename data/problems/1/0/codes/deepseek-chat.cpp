/*

Here is the C++ code to solve the 0/1 Knapsack problem:

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
- **Input Reading**: The first line reads `N` (number of items) and `V` (backpack capacity). The next `N` lines read the volume `v[i]` and value `w[i]` of each item.
- **Dynamic Programming Array**: `dp[j]` represents the maximum value that can be achieved with a backpack capacity of `j`.
- **DP Update**: For each item, update the `dp` array from `V` down to `v[i]` to ensure each item is used at most once.
- **Output**: The final result is `dp[V]`, which is the maximum value that can be achieved with the given capacity.

This solution has a time complexity of \(O(N \times V)\) and a space complexity of \(O(V)\), which is efficient given the constraints.

*/