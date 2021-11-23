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
  void recTraversal(const TreeNode *root, vector<int> &tab)
  {
    if (root->left)
      recTraversal(root->left, tab);

    tab.push_back(root->val);

    if (root->right)
      recTraversal(root->right, tab);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> tab;
    if (root)
      recTraversal(root, tab);
    return tab;
  }
};

// Given the root of a binary tree, return the inorder traversal of its nodes'
// values.

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

// Example 4:

// Input: root = [1,2]
// Output: [2,1]

// Example 5:

// Input: root = [1,null,2]
// Output: [1,2]
