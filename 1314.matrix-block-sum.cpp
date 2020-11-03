/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 *
 * https://leetcode.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (73.91%)
 * Likes:    586
 * Dislikes: 100
 * Total Accepted:    22.4K
 * Total Submissions: 30.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * Given a m * n matrix mat and an integer K, return a matrix answer where each
 * answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j
 * - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
 * Output: [[12,21,16],[27,45,33],[24,39,28]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
 * Output: [[45,45,45],[45,45,45],[45,45,45]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n, K <= 100
 * 1 <= mat[i][j] <= 100
 * 
 */

#include "lc.hpp"

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> prefixBlockSum(M, vector<int>(N, 0));
        vector<vector<int>> ret(M, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                prefixBlockSum[i][j]  = mat[i][j] + (j==0?0:prefixBlockSum[i][j-1]);
            }
            for (int j = 0; i > 0 && j < N; j++) {
                prefixBlockSum[i][j] += prefixBlockSum[i-1][j];
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int rl = max(i - K, 0), rh = min(i + K, M-1);
                int cl = max(j - K, 0), ch = min(j + K, N-1);

                ret[i][j] = prefixBlockSum[rh][ch];
                if (cl > 0)
                    ret[i][j] -= prefixBlockSum[rh][cl-1];
                if (rl > 0)
                    ret[i][j] -= prefixBlockSum[rl-1][ch];
                if (cl > 0 && rl > 0)
                    ret[i][j] += prefixBlockSum[rl-1][cl-1];
            }
        }
        return ret;

    }
};
// @lc code=end

