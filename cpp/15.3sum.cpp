#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> sol;

    int len = nums.size();
    if (len < 3)
      return sol;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < len - 2; ++i)
    {
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
        break;

      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      if (nums[i] + nums[len - 2] + nums[len - 1] < 0)
        continue;

      int left = i + 1;
      int right = len - 1;

      while (left < right)
      {
        if (nums[i] + nums[left] + nums[right] < 0)
          ++left;
        else if (nums[i] + nums[left] + nums[right] > 0)
          --right;
        else
        {
          sol.push_back({nums[i], nums[left], nums[right]});
          while (nums[left] == nums[left + 1] && left + 1 < right)
            ++left;
          while (nums[right] == nums[right - 1] && left < right - 1)
            --right;
          ++left;
          --right;
        }
      }
    }

    return sol;
  }
};

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums
// [k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
// == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:

// Input: nums = []
// Output: []

// Example 3:

// Input: nums = [0]
// Output: []
