#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    set<int> rows;
    set<int> cols;

    for (int i = 0; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
        if (matrix[i][j] == 0)
        {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (int i = 0; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
        if (rows.count(i) > 0 || cols.count(j) > 0)
          matrix[i][j] = 0;
      }
    }
  }
};

// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's, and return the matrix.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
