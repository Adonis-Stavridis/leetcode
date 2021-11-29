#include <vector>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
private:
  unordered_map<Node *, Node *> clones;

public:
  Node *cloneGraph(Node *node)
  {
    if (!node)
      return nullptr;

    if (clones.count(node) == 0)
    {
      clones[node] = new Node(node->val);
      for (Node *elem : node->neighbors)
      {
        clones[node]->neighbors.push_back(cloneGraph(elem));
      }
    }

    return clones[node];
  }
};
