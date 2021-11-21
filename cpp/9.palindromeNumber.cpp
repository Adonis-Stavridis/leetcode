using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;

    int initial = x;
    long int reversed = 0;
    while (x)
    {
      int right = x % 10;
      x /= 10;

      reversed *= 10;
      reversed += right;
    }

    return initial == reversed;
  }
};

// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For
// example, 121 is palindrome while 123 is not.

// Example 1:

// Input: x = 121
// Output: true

// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it 
// becomes
// 121-. Therefore it is not a palindrome.

// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Example 4:

// Input: x = -101
// Output: false
