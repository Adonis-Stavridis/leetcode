#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> sol;
    sol.push_back({1});
    int index = 1;
    while (index < numRows)
    {
      vector<int> step;
      step.push_back(1);
      for (int j = 0; j < sol[index - 1].size() - 1; j++)
      {
        step.push_back(sol[index - 1][j] + sol[index - 1][j + 1]);
      }
      step.push_back(1);
      sol.push_back(step);
      index++;
    }
    return sol;
  }
};

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]
