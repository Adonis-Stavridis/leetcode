#include <vector>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> temp = nums1;
    temp.insert(temp.end(), nums2.begin(), nums2.end());

    sort(temp.begin(), temp.end());

    int half = temp.size() / 2;
    if (temp.size() % 2 == 0 && half > 0)
      return (double)(temp[half - 1] + temp[half]) / 2;
    else
      return temp[half];
  }
};

// TODO: Not optimal

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return
// the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Example 3:

// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000

// Example 4:

// Input: nums1 = [], nums2 = [1]
// Output: 1.00000

// Example 5:

// Input: nums1 = [2], nums2 = []
// Output: 2.00000
