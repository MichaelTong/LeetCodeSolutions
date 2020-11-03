/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 *
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 *
 * algorithms
 * Hard (36.88%)
 * Likes:    609
 * Dislikes: 121
 * Total Accepted:    26.1K
 * Total Submissions: 70.5K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, return the number of all possible attendance
 * records with length n, which will be regarded as rewardable. The answer may
 * be very large, return it after mod 10^9 + 7.
 * 
 * A student attendance record is a string that only contains the following
 * three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A record is regarded as rewardable if it doesn't contain more than one 'A'
 * (absent) or more than two continuous 'L' (late).
 * 
 * Example 1:
 * 
 * Input: n = 2
 * Output: 8 
 * Explanation:
 * There are 8 records with length 2 will be regarded as rewardable:
 * "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
 * Only "AA" won't be regarded as rewardable owing to more than one absent
 * times. 
 * 
 * 
 * 
 * Note:
 * The value of n won't exceed 100,000.
 * 
 * 
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * think this as a state machine when reading the sequence 
 */
class Solution {
public:
    int checkRecord(int n) {
        long M = 1000000007;
        
        long a0p = 1, a0l = 0, a0ll = 0, a1a = 0, a1p = 0, a1l = 0, a1ll = 0;
        
        for (int i = 1; i <= n; i++) {
            long a0p_new, a0l_new, a0ll_new, a1a_new, a1p_new, a1l_new, a1ll_new;
            a0p_new = (a0p%M+a0l%M+a0ll%M)%M;
            a0l_new = a0p%M;
            a0ll_new = a0l%M;
            a1a_new = (a0p%M + a0l%M + a0ll%M)%M;
            a1p_new = (a1a%M + a1p%M + a1l%M + a1ll%M)%M;
            a1l_new = (a1a%M + a1p%M)%M;
            a1ll_new = a1l%M;
            
            a0p = a0p_new;
            a0l = a0l_new;
            a0ll = a0ll_new;
            a1a = a1a_new;
            a1p = a1p_new;
            a1l = a1l_new;
            a1ll = a1ll_new;
        }
        return (int)((a0p + a0l + a0ll + a1a + a1p + a1l + a1ll)%M);
    }
};
// @lc code=end

