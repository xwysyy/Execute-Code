/*

Here is a C++ implementation of the 0/1 Knapsack problem based on your description:

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> v(N);
    vector<int> w(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    // Create a DP array where dp[j] will hold the max value for capacity j
    vector<int> dp(V + 1, 0);

    // Process each item one by one
    for (int i = 0; i < N; ++i) {
        // Traverse the dp array backward
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // The maximum value is the last element in dp array
    cout << dp[V] << endl;

    return 0;
}

/*

### Explanation:
1. The program starts by reading the number of items `N` and the capacity of the backpack `V`.
2. It then reads the volume and value of each item into vectors `v` and `w`.
3. A DP array `dp` of size `V + 1` is created to keep track of the maximum value obtainable for each capacity from `0` to `V`.
4. The main logic involves iterating over each item and updating the `dp` array backwards (to prevent using the same item multiple times).
5. Finally, it outputs the maximum value that can be achieved for the given backpack capacity. 

### Constraints:
This implementation is efficient given the constraints (1 ≤ N, V ≤ 10), as it uses a dynamic programming approach that runs in O(N * V) time.

*/