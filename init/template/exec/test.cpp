#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int N, V;
    vector<int> v, w;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        w.push_back(x);
    }

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(N, V, v, w);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}