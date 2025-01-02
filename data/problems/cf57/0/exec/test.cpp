#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> bottle(k);
    for (int i = 0; i < k; i++)
        cin >> bottle[i].first >> bottle[i].second;

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n, k, bottle);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}