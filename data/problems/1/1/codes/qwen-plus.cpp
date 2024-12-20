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

    // Initialize DP table
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i-1]] + w[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][V] << endl;
    return 0;
}

/*

This code solves the 0/1 knapsack problem using dynamic programming. It reads the number of items and the backpack's capacity, then the volume and value of each item. It initializes a DP table and fills it according to the knapsack problem's recurrence relation, finally outputting the maximum value that can be achieved.

*/