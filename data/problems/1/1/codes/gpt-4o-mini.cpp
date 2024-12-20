/*

Here is the C++ code to solve the 0/1 Knapsack problem as described in your question:

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
- We first read the number of items `N` and the capacity `V`.
- Then we read the volume (`v[i]`) and value (`w[i]`) for each item.
- A dynamic programming array `dp` is used to store the maximum value that can be achieved for each capacity up to `V`.
- We iterate through each item. For each item, we update the `dp` array in reverse to ensure that each item is only considered once.
- Finally, we output the maximum value achievable with the given capacity `V`.

*/