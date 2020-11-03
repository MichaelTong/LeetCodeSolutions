/*
 * @lc app=leetcode id=1240 lang=cpp
 *
 * [1240] Tiling a Rectangle with the Fewest Squares
 *
 * https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/
 *
 * algorithms
 * Hard (50.31%)
 * Likes:    222
 * Dislikes: 257
 * Total Accepted:    8.4K
 * Total Submissions: 16.6K
 * Testcase Example:  '2\n3'
 *
 * Given a rectangle of size n x m, find the minimum number of integer-sided
 * squares that tile the rectangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 2, m = 3
 * Output: 3
 * Explanation: 3 squares are necessary to cover the rectangle.
 * 2 (squares of 1x1)
 * 1 (square of 2x2)
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 5, m = 8
 * Output: 5
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: n = 11, m = 13
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 13
 * 1 <= m <= 13
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Use binary search on the number of squares.
 * The difficult part is how to use DFS/backtracking to check if it is possible
 * to fill the rectangle with a certain number of squares
 */

class Solution {
    int max_len, min_len;
    int M, N;
    vector<vector<int>> grid;
public:
    int tilingRectangle(int n, int m) {
        M = m;
        N = n;
        max_len = max(n, m);
        min_len = min(n, m);
        if (m == n) return 1;
        grid = vector<vector<int>>(m, vector<int>(n, 0));
        
        int l = 1, r = m*n + 1;
        int res = -1;
        while (l < r) {
            int mid = l + (r - l)/2;
            bool found = false;
            dfsTryFill(found, 0, 0, mid);
            if (found) {
                res = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    bool checkFillOne(int i, int j, int len) {
        if (i + len - 1 >= M || j + len - 1 >= N) return false;
        for (int r = i; r <= i + len - 1; r++) {
            for (int c = j; c <= j + len - 1; c++) {
                if (grid[r][c] != 0)
                    return false;
            }
        }
        return true;
    }
    
    void doFillOne(int i, int j, int len) {
        for (int r = i; r <= i + len - 1; r++) {
            for (int c = j; c <= j + len - 1; c++) {
                grid[r][c] = len;
            }
        }
    }
    
    void undoFillOne(int i, int j, int len) {
        for (int r = i; r <= i + len - 1; r++) {
            for (int c = j; c <= j + len - 1; c++) {
                grid[r][c] = 0;
            }
        }
    }
    
    void dfsTryFill(bool &found, int filledArea, int filledSquare, int maxSquare) {
        if (filledArea == M*N) {
            found = true;
            return;
        }
        if (filledSquare >= maxSquare) return;
        if (found) return;

        bool filled = false;
        for (int i = 0; i < M && !filled; i++) {
            for (int j = 0; j < N && !filled; j++) {
                if (grid[i][j] != 0) continue;
                // found a empty spot
                // try to fit a largest square here
                for (int len = 1; len <= max_len; len++) {
                    if (checkFillOne(i, j, len)) {
                        filled = true;
                        doFillOne(i, j, len);
                        dfsTryFill(found, filledArea + len*len, filledSquare + 1, maxSquare);
                        undoFillOne(i, j, len);
                    } else {
                        // it is impossible to try a longer length as smaller length cannot fit
                        break;
                    }
                }
            }
        }
    }
};
// @lc code=end

