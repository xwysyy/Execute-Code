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
    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n, k, a, h);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}