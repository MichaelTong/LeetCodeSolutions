/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (58.92%)
 * Likes:    1495
 * Dislikes: 61
 * Total Accepted:    204.1K
 * Total Submissions: 344.3K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 * 
 * 
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * 
 * 
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations. [1,2,1] is not valid because 1
 * is used twice.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: k = 3, n = 2
 * Output: []
 * Explanation: There are no valid combinations.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: k = 9, n = 45
 * Output: [[1,2,3,4,5,6,7,8,9]]
 * Explanation:
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 * ​​​​​​​There are no other valid combinations.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k >= n) return result;
        vector<int> path;
        dfs(k, 1, n, path, result);
        return result;
    }
    
    void dfs(const int k, const int start, const int n,
            vector<int> &path, vector<vector<int>> &result) {
        if (start > n) {
            return;
        } else if (k == 1 && n >= start && n <= 9) {
            path.push_back(n);
            result.push_back(path);
            path.pop_back();
            return;
        }
        for (int i = start; i < 10; i++) {
            path.push_back(i);
            dfs(k-1, i+1, n - i, path, result);
            path.pop_back();
        }
        return;
    }
};
// @lc code=end

