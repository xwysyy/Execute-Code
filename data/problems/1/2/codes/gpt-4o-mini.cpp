/*

Here's a C++ implementation of the 0/1 Knapsack problem using dynamic programming to find the maximum value that can be achieved given N items and a backpack of capacity V:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    
    // Input the number of items and the capacity of the backpack
    cin >> N >> V;
    vector<int> v(N), w(N);
    
    // Input the volumes and values of the items
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }
    
    // Create a DP array to store the maximum value for each capacity
    vector<int> dp(V + 1, 0);

    // Process each item
    for (int i = 0; i < N; ++i) {
        // Traverse the DP array in reverse to avoid overwriting results
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value for the given capacity V
    cout << dp[V] << endl;

    return 0;
}

/*

This code reads the number of items and the capacity of the backpack, then takes the volumes and values of the items as input. It uses dynamic programming to fill an array that keeps track of the maximum values that can be achieved for each possible capacity, finally outputting the maximum value achievable with the full backpack capacity.

*/