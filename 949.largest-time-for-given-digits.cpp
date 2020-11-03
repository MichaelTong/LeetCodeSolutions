/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 *
 * https://leetcode.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Medium (36.58%)
 * Likes:    407
 * Dislikes: 789
 * Total Accepted:    56.5K
 * Total Submissions: 155.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array arr of 4 digits, find the latest 24-hour time that can be
 * made using each digit exactly once.
 * 
 * 24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and
 * MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest
 * is 23:59.
 * 
 * Return the latest 24-hour time in "HH:MM" format.  If no valid time can be
 * made, return an empty string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,2,3,4]
 * Output: "23:41"
 * Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42",
 * "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times,
 * "23:41" is the latest.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [5,5,5,5]
 * Output: ""
 * Explanation: There are no valid 24-hour times as "55:55" is not valid.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [0,0,0,0]
 * Output: "00:00"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = [0,0,1,0]
 * Output: "10:00"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * arr.length == 4
 * 0 <= arr[i] <= 9
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {

        int max_time = -1;
        // prepare for the generation of permutations next.
        sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            ostringstream strstream;
            strstream << setw(2) << setfill('0') << max_time / 60
               << ":" << setw(2) << setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};
// @lc code=end

