/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (37.74%)
 * Likes:    2192
 * Dislikes: 201
 * Total Accepted:    179.8K
 * Total Submissions: 473.1K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,2,3]
 * Output: [3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = 0, cnt1 = 0;
        bool bcan1 = false;
        int can2 = 0, cnt2 = 0;
        bool bcan2 = false;
        for (int n : nums) {
            if (bcan1 && can1 == n) {
                cnt1++;
            } else if (bcan2 && can2 == n) {
                cnt2++;
            } else if (cnt1 == 0) {
                can1 = n;
                cnt1++;
                bcan1 = true;
            } else if (cnt2 == 0) {
                can2 = n;
                cnt2++;
                bcan2 = true;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;
        
        for (int n : nums) {
            if (bcan1 && n == can1) cnt1++;
            if (bcan2 && n == can2) cnt2++;
        }
        
        if (cnt1 > nums.size()/3) res.push_back(can1);
        if (cnt2 > nums.size()/3) res.push_back(can2);
        return res;
    }
};
// @lc code=end

