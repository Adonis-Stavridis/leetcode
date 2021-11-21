#include <string>
#include <cstring>

using namespace std;

// class Solution
// {
// public:
//   string longestPalindrome(string s)
//   {
//   }
// };

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int len = s.size();
    if (len == 0 || len == 1)
      return s;

    int current = 0;
    int start = 0;

    int i = 0;
    while (i < len)
    {
      int left = i;
      int right = i;

      while (right + 1 < len && s[left] == s[right + 1])
        right++;

      i = right + 1;

      while (left - 1 >= 0 && right + 1 < len && s[left - 1] == s[right + 1])
      {
        left--;
        right++;
      }

      if (right - left + 1 > current)
      {
        current = right - left + 1;
        start = left;
      }
    }

    return s.substr(start, current);
  }
};

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Example 3:

// Input: s = "a"
// Output: "a"

// Example 4:

// Input: s = "ac"
// Output: "a"
