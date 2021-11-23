#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution
{
public:
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    if (nums.empty())
      return nullptr;

    if (nums.size() == 1)
      return new TreeNode(nums[0]);

    int center = nums.size() / 2;
    vector<int> left = vector<int>(&nums[0], &nums[center]);
    vector<int> right = vector<int>(&nums[center + 1], &nums[nums.size()]);
    return new TreeNode(nums[center], sortedArrayToBST(left),
                        sortedArrayToBST(right));
  }
};

// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth of the two
// subtrees of every node never differs by more than one.

// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
