#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void recGen(int open, int closed, int size, string combination,
              vector<string> &sol)
  {
    if (combination.size() == size * 2)
    {
      sol.push_back(combination);
      return;
    }

    if (open < size)
      recGen(open + 1, closed, size, combination + '(', sol);
    if (closed < open)
      recGen(open, closed + 1, size, combination + ')', sol);
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> sol;
    recGen(0, 0, n, "", sol);
    return sol;
  }
};

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]
