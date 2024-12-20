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
    
    // DP array to store the maximum value that can be obtained with a given volume
    vector<int> dp(V + 1, 0);
    
    // Iterate over each item
    for(int i = 0; i < N; ++i) {
        // Update the DP array in reverse order to avoid using the same item multiple times
        for(int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    // The answer is the maximum value that can be obtained with the given capacity
    cout << dp[V] << endl;
    
    return 0;
}

/*

This code reads the number of items and the backpack's capacity, then reads the volume and value of each item. It uses dynamic programming to compute the maximum value that can be achieved without exceeding the backpack's capacity. The result is printed at the end.

*/