/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 *
 * https://leetcode.com/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (37.67%)
 * Likes:    244
 * Dislikes: 1118
 * Total Accepted:    51.9K
 * Total Submissions: 137.7K
 * Testcase Example:  '[197,130,1]'
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the
 * following rules:
 * 
 * For 1-byte character, the first bit is a 0, followed by its unicode code.
 * For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
 * followed by n-1 bytes with most significant 2 bits being 10.
 * 
 * This is how the UTF-8 encoding would work:
 * 
 * ⁠  Char. number range  |        UTF-8 octet sequence
 * ⁠     (hexadecimal)    |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠  0000 0000-0000 007F | 0xxxxxxx
 * ⁠  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * ⁠  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 
 * 
 * Given an array of integers representing the data, return whether it is a
 * valid utf-8 encoding.
 * 
 * 
 * Note:
 * The input is an array of integers. Only the least significant 8 bits of each
 * integer is used to store the data. This means each integer represents only 1
 * byte of data.
 * 
 * 
 * 
 * Example 1:
 * 
 * data = [197, 130, 1], which represents the octet sequence: 11000101 10000010
 * 00000001.
 * 
 * Return true.
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
 * character.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * data = [235, 140, 4], which represented the octet sequence: 11101011
 * 10001100 00000100.
 * 
 * Return false.
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
 * character.
 * The next byte is a continuation byte which starts with 10 and that's
 * correct.
 * But the second continuation byte does not start with 10, so it is invalid.
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
    /**
     * Output:
     * 1 -- 1 - byte
     * 2 -- intermediate
     * 3 -- 2 - byte
     * 4 -- 3 - byte
     * 5 -- 4 - byte
     * -1 -- illegal
     */
    int outputType(const int &d) {
        int masks[6] = {0, 0x80, 0xc0, 0xe0, 0xf0, 0xf8};
        if ((d >> 8) != 0) return -1;
        /*
        int mask0 = 0x0;
        int mask1 = 0x80; // 1000 0000
        int mask2 = 0xc0; // 1100 0000
        int mask3 = 0xe0; // 1110 0000
        int mask4 = 0xf0; // 1111 0000
        int mask5 = 0xf8; // 1111 1000*/
        for (int i = 1; i < 6; i++) {
            if ((d & masks[i]) == masks[i-1]) {
                return i;
            }
        }
        return -1;
    }
public:
    bool validUtf8(vector<int>& data) {
        int N = data.size();
        int expected = 0;
        
        for (int d : data) {
            int t = outputType(d);
            if (t == -1) return false;
            else if (expected > 0 && t != 2) {
                return false;
            } else if (expected > 0 && t == 2) {
                expected--;
            } else if (expected == 0 && t == 2) {
                return false;
            } else if (expected == 0 && t != 1) {
                expected = t - 2;
            }
        }
        
        return expected == 0;
    }
};
// @lc code=end

