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
  bool recTraversal(const TreeNode *left, const TreeNode *right)
  {
    if (!left && !right)
      return true;

    if (!left || !right)
      return false;

    if (left->val != right->val)
      return false;

    return recTraversal(left->left, right->right) &&
           recTraversal(left->right, right->left);
  }

  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;

    return recTraversal(root->left, root->right);
  }
};

// Given the root of a binary tree, check whether it is a mirror of itself (i.e.
// , symmetric around its center).

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false
