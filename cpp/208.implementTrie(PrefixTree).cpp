#include <string>

using namespace std;

class Trie
{
private:
  struct Node
  {
    struct Node *alpha[26] = {nullptr};
    bool isWord;
    Node() : isWord(false) {}
  };

  Node *trie;

public:
  Trie() : trie(new Node())
  {
  }

  void insert(string word)
  {
    Node *cur = trie;
    for (const char &c : word)
    {
      Node *inAlpha = cur->alpha[c - 'a'];
      if (!inAlpha)
        cur->alpha[c - 'a'] = new Node();
      cur = cur->alpha[c - 'a'];
    }
    cur->isWord = true;
  }

  bool search(string word)
  {
    Node *cur = trie;
    for (const char &c : word)
    {
      Node *next = cur->alpha[c - 'a'];
      if (!next)
        return false;
      cur = next;
    }

    return cur->isWord;
  }

  bool startsWith(string prefix)
  {
    Node *cur = trie;
    for (const char &c : prefix)
    {
      Node *next = cur->alpha[c - 'a'];
      if (!next)
        return false;
      cur = next;
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// A trie(pronounced as "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings.There are various
// applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class :

//     Trie() Initializes the trie object.void insert(String word) Inserts the
// string word into the trie.boolean search(String word) Returns true if the
// string word is in the trie(i.e., was inserted before),
//     and false otherwise.boolean startsWith(String prefix) Returns true if
// there is a previously inserted string word that has the prefix prefix, and
// false otherwise.

// Example 1 :

//     Input["Trie", "insert", "search", "search", "startsWith", "insert",
// "search"][[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output[null, null, true, false, true, null, true]

//     Explanation Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app"); // return True
