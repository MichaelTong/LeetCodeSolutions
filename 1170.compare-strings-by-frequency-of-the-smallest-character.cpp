/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 *
 * https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Easy (59.20%)
 * Likes:    285
 * Dislikes: 708
 * Total Accepted:    47.5K
 * Total Submissions: 80.1K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * Let's define a function f(s) over a non-empty string s, which calculates the
 * frequency of the smallest character in s. For example, if s = "dcce" then
 * f(s) = 2 because the smallest character is "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer,
 * where each answer[i] is the number of words such that f(queries[i]) < f(W),
 * where W is a word in words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so
 * f("cbd") < f("zaaaz").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * Output: [1,2]
 * Explanation: On the first query only f("bbb") < f("aaaa"). On the second
 * query both f("aaa") and f("aaaa") are both > f("cc").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] are English lowercase letters.
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
    int f(string s) {
        vector<int> fs(26, 0);
        for (char c : s) {
            fs[c-'a'] ++;
        }
        for (int i = 0; i < 26; i++) {
            if (fs[i] != 0)
                return fs[i];
        }
        return 0;
    }
    int upperNumberBS(vector<int> &flist, int x) {
        int first = 0, last = flist.size();
        while (first < last) {
            int mid = first + (last - first)/2;
            int midv = flist[mid];
            if (x > midv) {
                first = mid + 1;                
            } else if (x == midv) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return flist.size() - first;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> flist;
        for (int i = 0; i < words.size(); i++) {
            int wf = f(words[i]);
            flist.push_back(wf);
        }
        sort(flist.begin(), flist.end());
        vector<int> ret;
        for (string q : queries) {
            int qf = f(q);
            ret.push_back(upperNumberBS(flist, qf));
        }
        return ret;
    }
};
// @lc code=end

