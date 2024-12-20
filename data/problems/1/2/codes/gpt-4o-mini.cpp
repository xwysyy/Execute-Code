/*

Here's the C++ code to solve the 0/1 Knapsack problem as described:

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N+1); // volumes
    vector<int> w(N+1); // values

    for (int i = 1; i <= N; ++i) {
        cin >> v[i] >> w[i];
    }

    vector<int> dp(V + 1, 0); // dp array to store max values for each volume

    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl; // output the maximum value that can be achieved
    return 0;
}

/*

This code uses a dynamic programming approach to solve the 0/1 Knapsack problem. It initializes a `dp` array to keep track of the maximum values achievable for each possible backpack volume up to `V`. The algorithm efficiently updates the `dp` array in reverse order to ensure each item is only considered once for each volume. Finally, it outputs the maximum value obtainable in the backpack.

*/