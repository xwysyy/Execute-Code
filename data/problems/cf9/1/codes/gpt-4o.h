#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class SolutionTo solve the problem efficiently, we need to handle a series of queries that adjust the values in an array based on whether they are even or odd. The primary challenge is to ensure that our solution can handle up to 100,000 queries efficiently, especially considering that the array can also have up to 100,000 elements.

Here's a structured approach to solve the problem:

1. **Initial Setup**: 
   - Calculate the initial sum of the array.
   - Count the number of even and odd values in the array, as we'll need this to efficiently update sums when processing queries.

2. **Processing Queries**:
   - Each query will add a certain value to all even or odd numbers:
     - **Type 0 Query (Add to evens)**: Update the sum based on the count of even numbers and the value to be added.
     - **Type 1 Query (Add to odds)**: Update the sum based on the count of odd numbers and the value to be added.

3. **After each query**: 
   - Adjust the count of even and odd numbers in the array if necessary:
     - If an even number becomes odd (after a Type 0 query with odd addition), it transitions from the even count to the odd count.
     - If an odd number becomes even (after a Type 1 query with odd addition), it transitions from the odd count to the even count.

4. **Efficiency**:
   - Instead of directly modifying individual elements, adjust the sum based on the known count of evens or odds, and update counts as needed. This results in O(1) operations per query.

Here's the complete solution in C++:



#endif