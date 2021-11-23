#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int last = digits.size() - 1;
    int carry = 0;

    vector<int> sol = digits;
    if (digits[last] + 1 > 9)
    {
      sol[last] = 0;
      carry = 1;
      last--;
    }
    else
    {
      sol[last]++;
    }

    while (last >= 0 && carry)
    {
      sol[last] += carry;
      if (sol[last] > 9)
      {
        sol[last] = 0;
        last--;
      }
      else
      {
        carry--;
      }
    }

    if (carry)
      sol.insert(sol.begin(), carry);

    return sol;
  }
};

// You are given a large integer represented as an integer array digits, where
// each digits[i] is the ith digit of the integer. The digits are ordered from
// most significant to least significant in left-to-right order. The large
// integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].

// Example 3:

// Input: digits = [0]
// Output: [1]
// Explanation: The array represents the integer 0.
// Incrementing by one gives 0 + 1 = 1.
// Thus, the result should be [1].

// Example 4:

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].
