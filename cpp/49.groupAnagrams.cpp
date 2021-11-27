#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<int>> groups;

    for (int i = 0; i < strs.size(); ++i)
    {
      string element = strs[i];
      sort(element.begin(), element.end());
      groups[element].push_back(i);
    }

    vector<vector<string>> sol;
    for (auto element : groups)
    {
      sol.push_back({});
      for (int index : element.second)
      {
        sol.back().push_back(strs[index]);
      }
    }

    return sol;
  }
};

// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
