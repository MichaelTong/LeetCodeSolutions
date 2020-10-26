/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (15.44%)
 * Likes:    1867
 * Dislikes: 10423
 * Total Accepted:    632.2K
 * Total Submissions: 4.1M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered a whitespace character.
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str = "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str = "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign. Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str = "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: str = "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical digit or a +/- sign. Therefore no valid conversion could be
 * performed.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: str = "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer. Thefore INT_MIN (−2^31) is returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 200
 * s consists of English letters (lower-case and upper-case), digits, ' ', '+',
 * '-' and '.'.
 * 
 * 
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        int i;
        char c;
        int state = 0; // 0 not started, 1 positive number, -1 negative
        int INT_MAX_DIV = INT_MAX/10, INT_MAX_R = INT_MAX%10;
        int INT_MIN_DIV = INT_MIN/10, INT_MIN_R = INT_MIN%10;   
        for(i = 0; i < s.size(); i++) {
            c = s[i];
            if (c == ' ') {
                if (state == 0) continue;
                else break;
            } else if ( c <= '9' && c >= '0') {
                int d = c - '0';
                if (state == 0) state = 1;
                if (state == 1) {
                    if (ret > INT_MAX_DIV || (ret == INT_MAX_DIV && d > INT_MAX_R))
                        return INT_MAX;
                } else if (state == -1) {
                    if (ret < INT_MIN_DIV || (ret == INT_MIN_DIV && state*d < INT_MIN_R))
                        return INT_MIN;
                }
                ret = ret * 10 + state * d;
            } else if (state == 0 && c == '+') {
                state = 1;
            } else if (state == 0 && c == '-') {
                state = -1;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

