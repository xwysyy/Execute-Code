#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second;

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n, q, a, queries);
    get_usage(argv[0], argv[1]);

    // output
    for(auto &x: result)
        cout << x << "\n";

    return 0;
}