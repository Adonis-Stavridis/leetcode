#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i] == prev)
        return true;
      prev = nums[i];
    }

    return false;
  }
};

// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true

// Example 2:

// Input: nums = [1,2,3,4]
// Output: false

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
