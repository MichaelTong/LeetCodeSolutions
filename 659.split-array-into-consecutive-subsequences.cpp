/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (43.86%)
 * Likes:    1341
 * Dislikes: 439
 * Total Accepted:    51.6K
 * Total Submissions: 117.4K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * Given an array nums sorted in ascending order, return true if and only if
 * you can split it into 1 or more subsequences such that each subsequence
 * consists of consecutive integers and has length at least 3.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10000
 * 
 * 
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Greedy algorithm:
 * for each number in nums, since it is sorted, three cases can happen
 * 1) it can be added to a sequence (longer than 3), which means this sequence
 *    ends at x-1
 * 2) it must form a new sequence, so we need to grab two larger numbers from 
 *    nums
 * 3) otherwise, it means it is not possible
 * 
 * use a count hash map to record how many numbers we can use
 * use a tails hash_map to record how many sequences are expecting x as next
 * number.
 * 
 */
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> tails;
        for (int x : nums) {
            count[x]++;
        }
        for (int x : nums) {
            if (count[x] == 0) {
                //already used
                continue;
            } else if (tails[x] > 0) {
                // already has a sequence (>3) ending at x-1, 
                tails[x]--;
                tails[x+1]++;
            } else if (count[x+1] > 0 && count[x+2] > 0) {
                // form a new sequence (=3) ending at x+2
                tails[x+3]++;
                count[x+1]--;
                count[x+2]--;
            } else {
                return false;
            }
            count[x]--;
        }
        return true;
    }
};
// @lc code=end

