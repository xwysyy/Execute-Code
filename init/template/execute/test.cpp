#include <bits/stdc++.h>
#include "execute.h"
#include "solution.h"
using namespace std;
int main(int argc, char *argv[])
{
    catch_error(argc);

    // input
    vector<int> nums1, nums2;
    for (int i = 0; i < 1; i++)
    {
        nums1.push_back(i);
        nums2.push_back(i);
    }

    // solve
    Solution solution;
    get_usage(argv[0], argv[1]);
    set_cpu_limit();
    auto result = solution.solve(nums1, nums2);
    get_usage(argv[0], argv[1]);

    // output
    cout << result << "\n";

    return 0;
}