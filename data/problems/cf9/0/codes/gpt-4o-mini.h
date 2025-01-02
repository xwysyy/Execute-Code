#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class SolutionTo solve the problem effectively, we'll take advantage of the separation of odd and even elements instead of processing each element in the array for every query. 

### Breakdown of the Approach:

1. **Initial Calculation**:
   - First, we need to compute the sum of the array `a`.
   - We also need to count how many elements are odd and how many are even. This will help us know how many elements to affect with each query.

2. **Processing Queries**:
   - For a query of the form `0 x_j`, we'll add `x_j` to all even elements. This can be done by:
     - Keeping track of a cumulative addition for even elements.
   - For a query of the form `1 x_j`, we add `x_j` to all odd elements similarly by:
     - Keeping track of a cumulative addition for odd elements.
   
3. **Calculating Results**:
   - After processing each query, we compute the new sum of the array by adjusting the initial total sum:
     - The sum will be increased by `count_even * even_addition` for even additions.
     - The sum will be increased by `count_odd * odd_addition` for odd additions.

This way, each query can be processed in O(1) time after the initial calculations, leading to an overall efficient solution.

Here’s the implementation in C++:



#endif