#include <string>

using namespace std;

class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    int maxlen = max(num1.size(), num2.size());
    string sum(maxlen + 1, '0');
    int cntr = 0;
    int carry = 0;

    while (cntr < maxlen || carry > 0)
    {
      int tmp =
          (cntr < num1.size() ? (num1[num1.size() - 1 - cntr] - '0') : 0) +
          (cntr < num2.size() ? (num2[num2.size() - 1 - cntr] - '0') : 0) +
          carry;
      int right = tmp % 10;
      sum[maxlen - cntr] = right + '0';
      carry = tmp / 10;
      cntr++;
    }

    if (sum[0] == '0')
      sum.erase(0, 1);

    return sum;
  }
};

// Given two non-negative integers, num1 and num2 represented as string, return
// the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling
// large integers (such as BigInteger). You must also not convert the inputs to
// integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"

// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"

// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"
