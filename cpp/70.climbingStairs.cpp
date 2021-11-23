#include <vector>

using namespace std;

class Solution
{
public:
  int recClimbStairs(int n, vector<int> &tab)
  {
    if (n > 1 && tab[n] == -1)
      tab[n] = recClimbStairs(n - 1, tab) + recClimbStairs(n - 2, tab);

    return tab[n];
  }

  int climbStairs(int n)
  {
    vector<int> tab(n+1, -1);
    tab[0] = 1;
    tab[1] = 1;

    return recClimbStairs(n, tab);
  }
};

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
