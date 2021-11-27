#include <string>

using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    int count[26] = {0};

    for (const char &c : s)
    {
      count[c - 'a']++;
    }
    for (const char &c : t)
    {
      count[c - 'a']--;
    }

    for (int val : count)
    {
      if (val)
        return false;
    }

    return true;
  }
};

// Given two strings s and t, return true if t is an anagram of s, and false
// otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false
