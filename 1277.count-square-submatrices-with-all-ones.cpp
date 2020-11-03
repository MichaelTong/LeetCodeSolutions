/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 *
 * https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (73.13%)
 * Likes:    1344
 * Dislikes: 23
 * Total Accepted:    76.3K
 * Total Submissions: 104.4K
 * Testcase Example:  '[[0,1,1,1],[1,1,1,1],[0,1,1,1]]'
 *
 * Given a m * n matrix of ones and zeros, return how many square submatrices
 * have all ones.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [
 * [0,1,1,1],
 * [1,1,1,1],
 * [0,1,1,1]
 * ]
 * Output: 15
 * Explanation: 
 * There are 10 squares of side 1.
 * There are 4 squares of side 2.
 * There is  1 square of side 3.
 * Total number of squares = 10 + 4 + 1 = 15.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = 
 * [
 * ⁠ [1,0,1],
 * ⁠ [1,1,0],
 * ⁠ [1,1,0]
 * ]
 * Output: 7
 * Explanation: 
 * There are 6 squares of side 1.  
 * There is 1 square of side 2. 
 * Total number of squares = 6 + 1 = 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
 * 
 * 
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0) return 0;
        int N = matrix[0].size();
        if (N == 0) return 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i - 1 < 0 || j - 1 < 0) {
                        dp[i][j] = 1;
                        ans++;
                    } else {
                        dp[i][j] = min(dp[i-1][j-1], dp[i][j-1]);
                        dp[i][j] = min(dp[i][j], dp[i-1][j]);
                        dp[i][j] += 1;
                        ans += dp[i][j];
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

