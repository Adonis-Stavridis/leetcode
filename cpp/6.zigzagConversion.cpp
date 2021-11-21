#include <string>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    int len = s.size();
    if (len == 0 || len == 1 || numRows == 1)
      return s;

    string sol;
    string rows[numRows];
    int dir = 1;
    int curRow = 0;

    for (int i = 0; i < len; i++)
    {
      rows[curRow] += s[i];
      if (curRow + dir < 0 || curRow + dir >= numRows)
        dir *= -1;
      curRow += dir;
    }

    for (string row : rows)
      sol += row;

    return sol;
  }
};

// class Solution
// {
// public:
//   string convert(string s, int numRows)
//   {
//     int len = s.size();
//     if (len == 0 || len == 1 || numRows == 1)
//       return s;

//     string sol;
//     int visited = 0;
//     int i = 0;
//     bool down = true;
//     int offset = 0;

//     while (visited < len)
//     {
//       sol += s[i];
//       visited++;

//       int val = 0;
//       if (offset > 0 && offset < numRows - 1)
//       {
//         val = down ? offset : numRows - 1 - offset;
//         down = !down;
//       }

//       i += 2 * (numRows - 1 - val);

//       if (i >= len)
//       {
//         offset++;
//         i = offset;
//         down = true;
//       }
//     }

//     return sol;
//   }
// };

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a
// number of rows:

// string convert(string s, int numRows);

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
