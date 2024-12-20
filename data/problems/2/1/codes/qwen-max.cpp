/*

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    
    vector<int> v(N), w(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
    
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j <= V; ++j) {
            if (v[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1]);
            }
        }
    }
    
    cout << dp[N][V] << endl;
    return 0;
}

/*

This code uses dynamic programming to solve the 0/1 knapsack problem. It initializes a 2D vector `dp` where `dp[i][j]` represents the maximum value that can be achieved with the first `i` items and a backpack capacity of `j`. The solution iterates over each item and each possible volume, updating the `dp` table based on whether including the current item would increase the total value without exceeding the capacity. Finally, it outputs the maximum value that can be achieved with all `N` items and a backpack capacity of `V`.

*/