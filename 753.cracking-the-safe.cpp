/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 *
 * https://leetcode.com/problems/cracking-the-safe/description/
 *
 * algorithms
 * Hard (50.96%)
 * Likes:    478
 * Dislikes: 677
 * Total Accepted:    30.8K
 * Total Submissions: 60K
 * Testcase Example:  '1\n1'
 *
 * There is a box protected by a password. The password is a sequence of n
 * digits where each digit can be one of the first k digits 0, 1, ..., k-1.
 * 
 * While entering a password, the last n digits entered will automatically be
 * matched against the correct password.
 * 
 * For example, assuming the correct password is "345", if you type "012345",
 * the box will open because the correct password matches the suffix of the
 * entered password.
 * 
 * Return any password of minimum length that is guaranteed to open the box at
 * some point of entering it.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1, k = 2
 * Output: "01"
 * Note: "10" will be accepted too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, k = 2
 * Output: "00110"
 * Note: "01100", "10011", "11001" will be accepted too.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * n will be in the range [1, 4].
 * k will be in the range [1, 10].
 * k^n will be at most 4096.
 * 
 * 
 * 
 * 
 */

#include "lc.hpp"

// @lc code=start
/**
 * This is a more of math problem.
 * We need to find the shortest number sequence that each n subarray is a
 * different combination. and it holds all the combinations.
 * 
 * Try start from k = 2, and see that pattern:
 * 
 * n = 2 all possible numbers k = 2
 *  -> 00  go to 01
 *     01  go to 11
 *     10  
 *     11  go to 10
 * 
 * n = 3
 *  -> 000 go to 001
 *     001 go to 011
 *     010 go to 100
 *     011 go to 111
 *     100 
 *     101 go to 010
 *     110 go to 101
 *     111 go to 110
 *
 * start from 000...
 * we always try to add the largest number at the end
 * if the next window number is visited, use next largest number
 */
class Solution {
    unordered_map<string, int> index;
    void buildIndex(string &str, const int &n, const int &k) {
        if (str.size() == n-1) {
            index[str] = k - 1;
            return;
        }
        for (int i = 0; i < k; i++) {
            str += to_string(i);
            buildIndex(str, n, k);
            str.pop_back();
        }
    }
public:
    string crackSafe(int n, int k) {
        string temp;
        buildIndex(temp, n, k);
        string ret = "";
        string stopping_key = "";
        for (int i = 0; i < n; i++) {
            ret += to_string(0);
            if (i < n-1)
                stopping_key += to_string(0);
        }
        while (true) {
            string prefix = ret.substr(ret.size()-n+1, n-1);
            int to_append = index[prefix]--;
            if (prefix == stopping_key && to_append==0)
                break;
            ret += to_string(to_append);
        }
        return ret;
    }
};
// @lc code=end

