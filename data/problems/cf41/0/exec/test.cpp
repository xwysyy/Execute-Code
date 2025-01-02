#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int k, q;
    cin >> k >> q;
    vector<int> a(k), n(q);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
        cin >> n[i];
    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(k, q, a, n);
    get_usage(argv[0], argv[1]);

    // output
    for (auto &x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}