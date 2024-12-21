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
- `dp[j]` represents the maximum value that can be achieved with a backpack capacity of `j`.
- We iterate over each item and update the `dp` array from the highest capacity to the lowest to ensure that each item is only used once.
- The final result is stored in `dp[V]`, which gives the maximum value that can be achieved with the given capacity `V`.

*/