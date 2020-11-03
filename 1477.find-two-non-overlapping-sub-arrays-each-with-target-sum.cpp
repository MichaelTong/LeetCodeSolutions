/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 *
 * https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/
 *
 * algorithms
 * Medium (32.13%)
 * Likes:    535
 * Dislikes: 26
 * Total Accepted:    15.8K
 * Total Submissions: 47.8K
 * Testcase Example:  '[3,2,2,4,3]\n3'
 *
 * Given an array of integers arr and an integer target.
 * 
 * You have to find two non-overlapping sub-arrays of arr each with sum equal
 * target. There can be multiple answers so you have to find an answer where
 * the sum of the lengths of the two sub-arrays is minimum.
 * 
 * Return the minimum sum of the lengths of the two required sub-arrays, or
 * return -1 if you cannot find such two sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,2,2,4,3], target = 3
 * Output: 2
 * Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of
 * their lengths is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7,3,4,7], target = 7
 * Output: 2
 * Explanation: Although we have three non-overlapping sub-arrays of sum = 7
 * ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as
 * the sum of their lengths is 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [4,3,2,6,2,3,4], target = 6
 * Output: -1
 * Explanation: We have only one sub-array of sum = 6.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [5,5,4,4,5], target = 3
 * Output: -1
 * Explanation: We cannot find a sub-array of sum = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [3,1,1,1,5,1,2,1], target = 3
 * Output: 3
 * Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an answer
 * because they overlap.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 1000
 * 1 <= target <= 10^8
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
    /**
     * Use sliding window to find all the subarrays that have sum of target
     * and record their l, r locations
     *
     * Now design data structures that store the following information
     * for each index i in the array
     * 1) what is the minimum length of subarrays that appear before i (prefix)
     * 2) what is the minimum length of subarrays that appear after i (suffix)
     */
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        if (arr.size() == 0) return -1;
        int l = 0, r = 0;
        int sum = arr[0];
        int n = arr.size();
        vector<int> start_len(arr.size(), n+1);
        vector<int> end_len(arr.size(), n+1);
        vector<int> prefix(arr.size() + 1, 0);
        vector<int> suffix(arr.size(), 0);
        while (l <= r && l < arr.size() && r < arr.size()) {
            if (sum < target) {
                if (r == arr.size() - 1)
                    break;
                r++;
                sum += arr[r];
            } else if (sum > target) {
                if (l < r) {
                    sum -= arr[l];
                    l++;
                } else {
                    l++;
                    r++;
                    sum = arr[l];
                }
            } else {
                start_len[l] = r - l + 1;
                end_len[r] = r - l + 1;
                sum -= arr[l];
                l++;
                if (r == arr.size() - 1)
                    break;
                r++;
                sum += arr[r];
            }
        }
        
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                suffix[i] = start_len[i];
            } else {
                suffix[i] = min(start_len[i], suffix[i+1]);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                prefix[i] = end_len[0];
            } else {
                prefix[i] = min(prefix[i-1], end_len[i-1]);
            }
            
        }
        
        int min_len = n + 1;
        for (int i = 1; i < n; i++) {
            min_len = min(min_len, prefix[i] + suffix[i]);
        }
        return min_len >= n+1?-1:min_len;
    }
};
// @lc code=end

