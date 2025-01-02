#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, char>> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n, m, x, a);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}