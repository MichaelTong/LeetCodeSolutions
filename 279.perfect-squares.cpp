/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (47.80%)
 * Likes:    3520
 * Dislikes: 211
 * Total Accepted:    345.5K
 * Total Submissions: 718.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<long> dp(n+1, INT_MAX);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int max_square = (int)sqrt(i);
            if (max_square*max_square == i) {
                dp[i] = 1;
                continue;
            }
            for (int j = 1; j <= max_square; j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

