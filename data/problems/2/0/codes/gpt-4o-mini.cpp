/*

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
- This code implements the 0/1 Knapsack problem using dynamic programming.
- It reads the number of items and the backpack capacity, then the volume and value of each item.
- It uses a `dp` array to store the maximum value achievable for each capacity from `0` to `V`.
- The nested loop updates the `dp` array based on whether to include each item or not, ensuring that the total volume does not exceed the capacity.

*/