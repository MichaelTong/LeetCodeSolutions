/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (34.91%)
 * Likes:    445
 * Dislikes: 424
 * Total Accepted:    30.9K
 * Total Submissions: 88.3K
 * Testcase Example:  '"RXXLRXRXL"\n"XRLXXRRLX"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: true
 * Explanation: We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: start = "X", end = "L"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: start = "LLR", end = "RRL"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: start = "XL", end = "LX"
 * Output: true
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: start = "XLLR", end = "LXLX"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= start.length <= 10^4
 * start.length == end.length
 * Both start and end will only consist of characters in 'L', 'R', and 'X'.
 * 
 * 
 */
#include "lc.hpp"

// @lc code=start
class Solution {
    /**
     * L and R won't switch places because they can't cross each other
     * so if scan Ls and Rs in start and end,
     * we can always find a L/R in end when we find a L/R in start
     *
     * L can only go left, so L in end can't be at a larger index than L in start
     * R can only go right, so R in end can't be at a smaller index than R in start
     */
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while (true) {
            while(i < start.size() && start[i] != 'L' && start[i] != 'R') {
                i++;
            }
            
            while (j < end.size() && end[j] != 'L' && end[j] != 'R') {
                j++;
            }
            if (!(i != start.size()&&j != end.size()||i == start.size()&&j == end.size())) return false;
            if (i==start.size() && j == end.size()) return true;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && j > i) return false;
            if (start[i] == 'R' && j < i) return false;
            i++;
            j++;
        }
        return true;
    }
};
// @lc code=end

