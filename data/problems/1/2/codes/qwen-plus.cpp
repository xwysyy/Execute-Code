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

This code snippet solves the 0/1 knapsack problem using dynamic programming. It reads the number of items and the capacity of the backpack, followed by the volume and value of each item. It then computes and outputs the maximum value that can be achieved without exceeding the backpack's capacity.

*/