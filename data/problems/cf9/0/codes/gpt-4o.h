#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class SolutionTo solve this problem, we need to efficiently process a series of queries on an array. Each query either adds a specific value to all even elements or to all odd elements of the array. After each query, we also need to compute the sum of the modified array. Given the constraints, iterating over the array for each query would be too slow. Instead, we can use an optimized approach as explained below.

### Solution Approach:

1. **Initial Setup:**
   - Calculate the initial sum of the array.
   - Count the number of even and odd elements in the array.
   - Calculate the sum of even elements and the sum of odd elements separately.

2. **Processing Queries:**
   - For each query:
     - If the query type is `0 x_j`: Add `x_j` to every even element:
       - Update the sum of even elements by adding `x_j * count_of_evens`.
       - If `x_j` is odd, all even elements become odd after addition. Update the counters accordingly.
     - If the query type is `1 x_j`: Add `x_j` to every odd element:
       - Update the sum of odd elements by adding `x_j * count_of_odds`.
       - If `x_j` is odd, all odd elements become even after addition. Update the counters accordingly.
   - After processing each query, calculate the total sum of the array using the sums of odd and even elements.
   - Store the current total sum in the result list.

3. **Return the Result:**
   - The result list contains the sum of the array after each query, which is the required output.

This approach allows each query to be processed in constant time, leading to an overall time complexity of O(n + q), which is efficient given the problem constraints.

Here's the implementation:



#endif