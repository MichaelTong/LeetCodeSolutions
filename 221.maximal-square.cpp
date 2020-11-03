/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (37.93%)
 * Likes:    3639
 * Dislikes: 93
 * Total Accepted:    297.4K
 * Total Submissions: 781.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        int M = matrix.size();
        if (M == 0) return 0;
        int N = matrix[0].size();
        if (N == 0) return 0;
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                        dp[i][j] += 1;
                    }
                }
                ret = max(ret, dp[i][j]*dp[i][j]);
            }
        }
        return ret;
    }
};
// @lc code=end

