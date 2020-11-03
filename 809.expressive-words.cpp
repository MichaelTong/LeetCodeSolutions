/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 *
 * https://leetcode.com/problems/expressive-words/description/
 *
 * algorithms
 * Medium (46.96%)
 * Likes:    373
 * Dislikes: 941
 * Total Accepted:    54.1K
 * Total Submissions: 115.9K
 * Testcase Example:  '"heeellooo"\n["hello", "hi", "helo"]'
 *
 * Sometimes people repeat letters to represent extra feeling, such as "hello"
 * -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have
 * groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".
 * 
 * For some given string S, a query word is stretchy if it can be made to be
 * equal to S by any number of applications of the following extension
 * operation: choose a group consisting of characters c, and add some number of
 * characters c to the group so that the size of the group is 3 or more.
 * 
 * For example, starting with "hello", we could do an extension on the group
 * "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has
 * size less than 3.  Also, we could do another extension like "ll" -> "lllll"
 * to get "helllllooo".  If S = "helllllooo", then the query word "hello" would
 * be stretchy because of these two extension operations: query = "hello" ->
 * "hellooo" -> "helllllooo" = S.
 * 
 * Given a list of query words, return the number of words that are
 * stretchy. 
 * 
 * 
 * 
 * 
 * Example:
 * Input: 
 * S = "heeellooo"
 * words = ["hello", "hi", "helo"]
 * Output: 1
 * Explanation: 
 * We can extend "e" and "o" in the word "hello" to get "heeellooo".
 * We can't extend "helo" to get "heeellooo" because the group "ll" is not size
 * 3 or more.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= len(S) <= 100.
 * 0 <= len(words) <= 100.
 * 0 <= len(words[i]) <= 100.
 * S and all words in words consist only of lowercase letters
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Basic idea is split each word into different groups of same character.
 * For a word to be stretchy to S, the groups must match S's groups.
 * Then, for each group, if length in S is less than 3, length in word must be
 * the same, meaning it is not streched.
 * If length in S is longer than 3, length in words must be less than length in
 * S.  
 */
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret;
        for (const string &w : words) {
            bool fail = false;
            int i = 0, j = 0;
            while(i < w.size() && j < S.size()) {
                char c = w[i];
                int num = 1;
                if (w[i] != S[j]) {
                    fail = true;
                    break;
                }
                int jnum = 1;
                while (++i < w.size() && w[i] == c) num++;
                while (++j < S.size() && S[j] == c) jnum++;
                if (jnum == num || (jnum > num && jnum >= 3)) continue;
                fail = true;
                break;
            }
            if (fail) continue;
            if (i == w.size() && j == S.size())
                ret++;
        }
        return ret;
    }
};
// @lc code=end

