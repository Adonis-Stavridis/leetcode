#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval)
  {
    vector<vector<int>> sol;

    int index = 0;
    while (index < intervals.size() && intervals[index][1] < newInterval[0])
    {
      sol.push_back(intervals[index]);
      ++index;
    }

    while (index < intervals.size() && intervals[index][0] <= newInterval[1])
    {
      newInterval[0] = min(newInterval[0], intervals[index][0]);
      newInterval[1] = max(newInterval[1], intervals[index][1]);
      ++index;
    }

    sol.push_back(newInterval);

    while (index < intervals.size())
    {
      sol.push_back(intervals[index]);
      ++index;
    }

    return sol;
  }
};
