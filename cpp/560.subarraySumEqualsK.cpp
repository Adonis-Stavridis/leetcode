#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> hashmap = {{0, 1}};
    int sol = 0;
    int sum = 0;

    for (const int &num : nums)
    {
      sum += num;
      sol += hashmap[sum - k];
      hashmap[sum]++;
    }

    return sol;
  }
};

// Given an array of integers nums and an integer k, return the total number of
// continuous subarrays whose sum equals to k.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
