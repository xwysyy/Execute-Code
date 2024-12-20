/*

Here is the C++ code to solve the 0/1 Knapsack problem using dynamic programming:

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
- We use a 1D dynamic programming array `dp` where `dp[j]` represents the maximum value that can be achieved with a knapsack capacity of `j`.
- For each item, we iterate backwards through the possible capacities from `V` down to the volume of the current item `v[i]`.
- This backward iteration ensures that each item is only considered once per capacity.
- We update `dp[j]` to be the maximum of its current value or the value obtained by including the current item (`dp[j - v[i]] + w[i]`).
- Finally, `dp[V]` will contain the maximum value that can be achieved with the full capacity `V`.

*/