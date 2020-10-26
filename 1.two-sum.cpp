/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.82%)
 * Likes:    17508
 * Dislikes: 627
 * Total Accepted:    3.5M
 * Total Submissions: 7.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unordered_set<int>> num_index;

        for(int i = 0; i < nums.size(); i++) {
            num_index[nums[i]].insert(i);
            int need = target - nums[i];
            if (num_index.find(need) != num_index.end()) {
                if (num_index[need].find(i) != num_index[need].end() 
                        && num_index[need].size() == 1)
                    continue;
                for (int j : num_index[need]) {
                    if (i != j) {
                        return {i, j};
                    }
                }
            }

        }
        return {-1, -1};
    }
};
// @lc code=end

