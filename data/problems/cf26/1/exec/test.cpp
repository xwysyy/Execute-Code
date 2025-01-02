#include <bits/stdc++.h>
#include "execute.h"
#include "std.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    int n,m,k;cin>>n>>m>>k;
    int x,y;cin>>x>>y;
    vector<pair<int,int>> a(k);
    for(auto &[X,Y]:a)cin>>X>>Y;

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(n,m,k,x,y,a);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}