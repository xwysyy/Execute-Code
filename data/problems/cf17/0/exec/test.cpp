#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(a, b, c, d);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}