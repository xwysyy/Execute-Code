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

This code implements a solution using dynamic programming to solve the 0/1 Knapsack problem. The `dp` array is used to store the maximum value that can be achieved with a given capacity and a subset of items. The final answer, which is the maximum value that can be achieved with the full set of items and the full capacity, is stored in `dp[N][V]`.

*/