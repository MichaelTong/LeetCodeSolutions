/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (44.42%)
 * Likes:    796
 * Dislikes: 1275
 * Total Accepted:    242.8K
 * Total Submissions: 545K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowels_index;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels_index.push_back(i);
            }
        }
        for (int i = 0, j = vowels_index.size() - 1; i < j; i++, j--) {
            swap(s[vowels_index[i]], s[vowels_index[j]]);
        }
        return s;
    }
};
// @lc code=end

