#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<array<int, 3>> ops(m);
    for (int i = 0; i < m; i++)
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n, m, a, ops);
    get_usage(argv[0], argv[1]);

    // output
    for (auto &x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}