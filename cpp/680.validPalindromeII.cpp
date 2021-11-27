#include <string>

using namespace std;

class Solution
{
public:
  bool isValid(string s, int left, int right)
  {
    // verify palindrome
    int len = right - left + 1;
    for (int i = 0; i < len / 2; i++)
    {
      if (s[left + i] != s[right - i])
        return false;
    }
    return true;
  }

  bool validPalindrome(string s)
  {
    int left = 0;
    int right = s.size() - 1;

    while (s[left] == s[right] && left < right)
    {
      left++;
      right--;
    }

    if (left < right)
      return isValid(s, left, right - 1) ||
             isValid(s, left + 1, right);

    return true;
  }
};

// Given a string s, return true if the s can be palindrome after deleting at
// most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true

// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:

// Input: s = "abc"
// Output: false
