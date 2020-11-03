/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 *
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
 *
 * algorithms
 * Medium (54.84%)
 * Likes:    504
 * Dislikes: 46
 * Total Accepted:    31.9K
 * Total Submissions: 58.1K
 * Testcase Example:  '[1,2,3,3,4,4,5,6]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into sets of k consecutive numbers
 * Return True if its possible otherwise return False.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,3,4,4,5,6], k = 4
 * Output: true
 * Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
 * Output: true
 * Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and
 * [9,10,11].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3,2,2,1,1], k = 3
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 * Explanation: Each array should be divided in subarrays of size 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= nums.length
 * 
 * Note: This question is the same as 846:
 * https://leetcode.com/problems/hand-of-straights/
 */
#include "lc.hpp"
// @lc code=start
/**
 * Count the appearances of each number in a treemap(map)
 * Then from the smallest number, reduce their counts.
 */
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> count;
        for (int i : nums) {
            if (count.find(i) == count.end()) {
                count[i] = 1;
            } else
                count[i]++;
        }
        
        while (count.size() > 0) {
            int first = count.begin()->first;
            for (int i = first; i < first + k; i++) {
                if (count.find(i) == count.end()) return false;
                int c = count[i];
                if (c == 1) count.erase(i);
                else count[i]--;
            }
        }
        return true;
    }
};
// @lc code=end

