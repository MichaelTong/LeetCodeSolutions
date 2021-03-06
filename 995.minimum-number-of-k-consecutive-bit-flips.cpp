/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 *
 * https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
 *
 * algorithms
 * Hard (47.22%)
 * Likes:    389
 * Dislikes: 34
 * Total Accepted:    13.7K
 * Total Submissions: 28.8K
 * Testcase Example:  '[0,1,0]\n1'
 *
 * In an array A containing only 0s and 1s, a K-bit flip consists of choosing a
 * (contiguous) subarray of length K and simultaneously changing every 0 in the
 * subarray to 1, and every 1 in the subarray to 0.
 * 
 * Return the minimum number of K-bit flips required so that there is no 0 in
 * the array.  If it is not possible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [0,1,0], K = 1
 * Output: 2
 * Explanation: Flip A[0], then flip A[2].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,1,0], K = 2
 * Output: -1
 * Explanation: No matter how we flip subarrays of size 2, we can't make the
 * array become [1,1,1].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [0,0,0,1,0,1,1,0], K = 3
 * Output: 3
 * Explanation:
 * Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
 * Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
 * Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * 1 <= K <= A.length
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Greedy + Events
 * Greedy part:
 * If the left most bit is 0, we must flip it, otherwise, we still need to go
 * back to the beginning to slip it.
 * 
 * Events part: 
 * The tricky part is how to reduce the true flip operations in the
 * program. The naive approach is flip K elements once we decide to flip, then
 * go to next elements. 
 * This cost a lot. we can use another array to indicate the regions of flipeed.
 * 
 * Set a hint array, and in the beginning, we have our variable flip to be 0, it
 * means we read the element in A as it is.
 * Once we decide we need to flip at a certain index and end at another index,
 * we mark the indexes in the hint array. And flip gets flipped.
 * 
 * Assume we need to flip again, in the previous region, we set the markers again.
 * Once we get a hint we get flip flipped.
 * 
 * e.g. K = 8
 *       [0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, ...]
 * flip            1           0        1           0
 *                 \- flip once\        \           \- no longer flipped
 *                             \        \- end of first flip, so number after 
 *                             \           this only flip once
 *                             \- the next region is flipped again
 */
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N = A.size();
        int hint[N];
        memset(hint, 0, N*sizeof(int));
        int ret = 0, flip = 0; // flip indicate we need to perform flip when we meet 0 or 1
        
        for (int i = 0; i < N; i++) {
            if (hint[i] == 1) {
                flip ^= 1;
            }
            
            if (A[i] == flip) { //must flip
                ret++;
                if (i + K > N) return -1;
                flip ^= 1;
                if (i + K < N) hint[i + K] = 1;
                
            }
        }
        return ret;
    }
};
// @lc code=end

