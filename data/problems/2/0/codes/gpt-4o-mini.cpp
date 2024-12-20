/*

Here is the C++ code to solve the 0/1 Knapsack problem based on the given constraints:

*/

#include <iostream>
#include <vector>
#include <algorithm>

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
- The code begins by reading the number of items (`N`) and the volume capacity of the backpack (`V`).
- It then reads the volumes and values of the items into vectors `v` and `w`.
- `dp[j]` is used to store the maximum value that can be attained with a capacity of `j`.
- We iterate over each item and update the `dp` array in reverse order to prevent overwriting results from the current iteration.
- Finally, the maximum value achievable with the full capacity `V` is printed. 

You can easily compile and run this code with any C++ compiler.

*/