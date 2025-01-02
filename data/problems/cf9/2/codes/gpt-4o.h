#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class SolutionTo solve the problem of processing queries on an integer array, we need to efficiently handle the addition operations and compute the sum of the array after each query. The key is to manage the operations for even and odd elements separately and update the array sum accordingly.

Here's how we can approach the solution:

### Steps to Solution:

1. **Initialize the Total Sum:**
   - Start by calculating the initial sum of all elements in the array `a`.

2. **Separate Even and Odd Sums:**
   - Calculate the sum of all even-valued elements (`even_sum`) and odd-valued elements (`odd_sum`).
   - Also, count the number of even elements (`even_count`) and odd elements (`odd_count`).

3. **Process Each Query:**
   - For queries of the type **"0 x_j"**:
     - `x_j` is added to each even element in the array.
     - Update the `even_sum` by adding `(even_count * x_j)` to it.
     - After adding `x_j` to each even element, if `x_j` is odd, the parity of those elements will change. Thus, swap the counts and sums of even and odd elements.
   - For queries of the type **"1 x_j"**:
     - `x_j` is added to each odd element in the array.
     - Update the `odd_sum` by adding `(odd_count * x_j)` to it.
     - As above, if `x_j` is odd, swap the parity of those elements, which requires swapping counts and sums.

4. **Update and Store the Total Sum:**
   - After processing each query, calculate and store the new total sum (`even_sum + odd_sum`) in the results.

5. **Return Results:**
   - Finally, return the sum of the array after each query in a list.

This approach ensures that the operations are performed in constant time for each query, making it suitable for the input constraints.

Here's the implementation in C++:



#endif