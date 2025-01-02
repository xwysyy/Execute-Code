#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class SolutionTo solve the problem of processing a series of queries that modify the elements of an array based on their parity (odd or even), we can optimize our approach by keeping track of separate sums for odd and even elements. Instead of updating all elements in the array for each query, we maintain cumulative offsets for odd and even integers. This allows us to compute the modified sum efficiently after each query.

Here’s the step-by-step approach to the solution:

1. **Initialization of Sums**: Calculate the initial sum of the elements in the array `a` while also keeping track of the sum of even and odd elements separately. This will help us determine the initial state before any queries are applied.

2. **Processing Queries**: For each query:
   - If the query indicates modifying even elements (`0 x_j`), add `x_j` to the `even_offset`.
   - If the query indicates modifying odd elements (`1 x_j`), add `x_j` to the `odd_offset`.
   - After updating the appropriate offset, calculate the total sum using the initial sums of even and odd elements combined with the current offsets.

3. **Efficient Output**: Instead of modifying the actual array for each query, just output the modified sums after each query based on the offsets.

Here’s the implementation of the above approach:



#endif