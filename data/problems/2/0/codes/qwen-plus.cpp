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

    // DP table where dp[i][j] represents the maximum value that can be obtained
    // with the first i items and a knapsack capacity of j.
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i - 1]) {
                // Option to take the item or not take it
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            } else {
                // Cannot take the item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][V] << endl;
    return 0;
}

/*

This code reads the number of items \(N\) and the capacity \(V\) of the backpack from the input. It then reads the volume and value of each item into vectors `v` and `w`. The dynamic programming (DP) approach is used to fill a table `dp` where `dp[i][j]` represents the maximum value that can be achieved using the first \(i\) items with a total volume not exceeding \(j\). Finally, it outputs the maximum value that can be achieved for the given capacity \(V\).

*/