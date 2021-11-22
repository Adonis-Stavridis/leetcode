#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> ret;
    int len = nums.size();
    if (len < 3)
      return ret;

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 2; ++i)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; //to avoid duplicates through first value
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
        break; //no solution
      if (nums[i] + nums[len - 2] + nums[len - 1] < 0)
        continue; //"i" is too small

      int j = i + 1, k = len - 1;
      while (j < k)
      {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0)
          --k;
        else if (sum < 0)
          ++j;
        else
        {
          ret.push_back({nums[i], nums[j], nums[k]});
          do
          {
            ++j;
          } while (nums[j] == nums[j - 1] && j < k);
          //to avoid duplicates through second value
          do
          {
            --k;
          } while (nums[k] == nums[k + 1] && j < k);
          //to avoid duplicates through third value
        }
      }
    }

    return ret;
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
