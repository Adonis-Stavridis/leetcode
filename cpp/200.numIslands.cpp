#include <vector>

using namespace std;

class Solution
{
private:
  void helper(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
      return;

    if (grid[i][j] == '0')
      return;

    grid[i][j] = '0';
    helper(grid, i - 1, j);
    helper(grid, i + 1, j);
    helper(grid, i, j - 1);
    helper(grid, i, j + 1);
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int num = 0;

    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[i].size(); ++j)
      {
        if (grid[i][j] == '1')
        {
          ++num;
          helper(grid, i, j);
        }
      }
    }

    return num;
  }
};

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are
// all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
