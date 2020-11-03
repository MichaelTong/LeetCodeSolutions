/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (59.14%)
 * Likes:    3919
 * Dislikes: 233
 * Total Accepted:    727.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
public:
    /**
     * Boyer-Moore Voting
     */
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate ? 1 : -1);
        }
        
        return candidate;
    }
};
// @lc code=end

