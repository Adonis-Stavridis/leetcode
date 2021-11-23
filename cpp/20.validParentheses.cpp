#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> mystack;

    for (const char &c : s)
    {
      char top = mystack.empty() ? '0' : mystack.top();
      if ((top == '(' && c == ')') ||
          (top == '{' && c == '}') ||
          (top == '[' && c == ']'))
        mystack.pop();
      else
        mystack.push(c);
    }

    return mystack.empty();
  }
};

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.

// Example 1:

// Input: s = "()"
// Output: true

// Example 2:

// Input: s = "()[]{}"
// Output: true

// Example 3:

// Input: s = "(]"
// Output: false

// Example 4:

// Input: s = "([)]"
// Output: false

// Example 5:

// Input: s = "{[]}"
// Output: true
