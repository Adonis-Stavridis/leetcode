#include <string>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty())
      return 0;

    int i = 0, j = 0;

    while (i < haystack.size())
    {
      if (haystack[i] == needle[j])
      {
        j++;
      }
      else
      {
        i -= j;
        j = 0;
      }

      if (j == needle.size())
      {
        return i - j + 1;
      }

      i++;
    }

    return -1;
  }
};

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great
// question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty
// string. This is consistent to C's strstr() and Java's indexOf().

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Example 3:

// Input: haystack = "", needle = ""
// Output: 0
