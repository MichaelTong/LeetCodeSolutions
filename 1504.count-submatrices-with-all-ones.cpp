/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 *
 * https://leetcode.com/problems/count-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (62.74%)
 * Likes:    585
 * Dislikes: 32
 * Total Accepted:    14K
 * Total Submissions: 22.8K
 * Testcase Example:  '[[1,0,1],[1,1,0],[1,1,0]]'
 *
 * Given a rows * columns matrix mat of ones and zeros, return how many
 * submatrices have all ones.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,0,1],
 * [1,1,0],
 * [1,1,0]]
 * Output: 13
 * Explanation:
 * There are 6 rectangles of side 1x1.
 * There are 2 rectangles of side 1x2.
 * There are 3 rectangles of side 2x1.
 * There is 1 rectangle of side 2x2. 
 * There is 1 rectangle of side 3x1.
 * Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,1,1,0],
 * [0,1,1,1],
 * [1,1,1,0]]
 * Output: 24
 * Explanation:
 * There are 8 rectangles of side 1x1.
 * There are 5 rectangles of side 1x2.
 * There are 2 rectangles of side 1x3. 
 * There are 4 rectangles of side 2x1.
 * There are 2 rectangles of side 2x2. 
 * There are 2 rectangles of side 3x1. 
 * There is 1 rectangle of side 3x2. 
 * Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[1,1,1,1,1,1]]
 * Output: 21
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= rows <= 150
 * 1 <= columns <= 150
 * 0 <= mat[i][j] <= 1
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * DP, from top left, record for each cell, what is the maximum length of
 * consecutive ones ending at this cell.
 * So dp[i][j] = dp[i][j-1] + 1 if mat[i][j] == 1
 * 
 * Then for cell at (i, j) the rectangles uses i, j as right bottom corner
 * has dp[i][j] + dp[i-1][j] + ... until a dp[ii][jj] is zero
 * and the width is currently the smallest one.
 */

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        
        int ret = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 1) {
                    dp[r][c] = c - 1 >= 0?(dp[r][c-1] + 1): 1;
                    int width = dp[r][c];
                    int row = r;
                    while (width > 0) {
                        ret += width;
                        row --;
                        if (row >= 0)
                            width = min(width, dp[row][c]);
                        else
                            break;
                        
                    }
                } else {
                    dp[r][c] = 0;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

