#include <string>

using namespace std;

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    int counter = 0;

    for (int i = 0; i < s.size(); ++i)
    {
      char &c = s[i];
      switch (c)
      {
      case '(':
        ++counter;
        break;
      case ')':
        if (counter == 0)
          c = '_';
        else
          --counter;

      default:
        break;
      }
    }

    for (int i = s.size() - 1; i >= 0 && counter > 0; --i)
    {
      char &c = s[i];
      if (c == '(')
      {
        c = '_';
        --counter;
      }
    }

    s.erase(remove(s.begin(), s.end(), '_'), s.end());

    return s;
  }
};

// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in
// any positions ) so that the resulting parentheses string is valid and return
// any valid string.

// Formally, a parentheses string is valid if and only if:

//     It is the empty string, contains only lowercase characters, or
//     It can be written as AB (A concatenated with B), where A and B are valid
// strings, or
//     It can be written as (A), where A is a valid string.

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

// Example 4:

// Input: s = "(a(b(c)d)"
// Output: "a(b(c)d)"
