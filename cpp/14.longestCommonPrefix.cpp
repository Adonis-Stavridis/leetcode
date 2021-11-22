#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    sort(strs.begin(), strs.end());
    string front = strs[0];
    string back = strs[strs.size() - 1];

    string sol = "";
    int i = 0;
    while (i < front.size() && front[i] == back[i])
    {
      sol += front[i];
      i++;
    }

    return sol;
  }
};

// class Solution
// {
// public:
//   string longestCommonPrefix(vector<string> &strs)
//   {
//     int i = 0;
//     string sol = "";

//     size_t minLen = strs[0].size();
//     for (int j = 1; j < strs.size(); j++)
//     {
//       minLen = min(minLen, strs[j].size());
//     }

//     while (i < minLen)
//     {
//       bool valid = true;
//       char current = strs[0][i];
//       for (int k = 1; k < strs.size(); k++)
//       {
//         valid = current == strs[k][i];
//         if (!valid)
//           return sol;
//       }

//       sol += current;
//       i++;
//     }

//     return sol;
//   }
// };

// Write a function to find the longest common prefix string amongst an array
// of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
