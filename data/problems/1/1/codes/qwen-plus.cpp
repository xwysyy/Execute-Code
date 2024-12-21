/*

*/

#include <iostream>
#include <vector>
#include <cstring> // For memset

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // dp[j] represents the maximum value that can be obtained with a capacity of j
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

This code snippet solves the 0/1 knapsack problem using dynamic programming. It reads the number of items and the backpack's capacity from the standard input, then iterates through each item to fill the `dp` table, which keeps track of the maximum value that can be achieved for each possible volume up to \(V\). Finally, it outputs the maximum value that can be achieved within the given capacity.

*/