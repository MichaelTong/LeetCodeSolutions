/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (47.72%)
 * Likes:    1094
 * Dislikes: 78
 * Total Accepted:    47K
 * Total Submissions: 98.4K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given string S and a dictionary of words words, find the number of words[i]
 * that is a subsequence of S.
 * 
 * 
 * Example :
 * Input: 
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S:
 * "a", "acd", "ace".
 * 
 * 
 * Note:
 * 
 * 
 * All words in words and S will only consists of lowercase letters.
 * The length of S will be in the range of [1, 50000].
 * The length of words will be in the range of [1, 5000].
 * The length of words[i] will be in the range of [1, 50].
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * grouping the words by their starting characters
 * then scan S, if a character much with a group, regroup the words in that group
 * by their next leading characters
 * 
 */
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<string>> prefix_words;
        for(string w : words) {
            prefix_words[w[0]].push_back(w);
        }
        int ret;
        for(char c : S) {
            vector<string> words = prefix_words[c];
            prefix_words[c] = vector<string>();
            for (string w : words) {
                if (w.size() == 1) ret++;
                else {
                    char cc = w[1];
                    prefix_words[cc].push_back(w.substr(1));
                }
            }
        }
        return ret;
    }
};
// @lc code=end

