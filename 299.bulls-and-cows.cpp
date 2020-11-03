/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (43.67%)
 * Likes:    837
 * Dislikes: 981
 * Total Accepted:    195.3K
 * Total Submissions: 444.7K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the Bulls and Cows game with your friend.
 * 
 * You write down a secret number and ask your friend to guess what the number
 * is. When your friend makes a guess, you provide a hint with the following
 * info:
 * 
 * 
 * The number of "bulls", which are digits in the guess that are in the correct
 * position.
 * The number of "cows", which are digits in the guess that are in your secret
 * number but are located in the wrong position. Specifically, the non-bull
 * digits in the guess that could be rearranged such that they become bulls.
 * 
 * 
 * Given the secret number secret and your friend's guess guess, return the
 * hint for your friend's guess.
 * 
 * The hint should be formatted as "xAyB", where x is the number of bulls and y
 * is the number of cows. Note that both secret and guess may contain duplicate
 * digits.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: secret = "1807", guess = "7810"
 * Output: "1A3B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1807"
 * ⁠ |
 * "7810"
 * 
 * Example 2:
 * 
 * 
 * Input: secret = "1123", guess = "0111"
 * Output: "1A1B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1123"        "1123"
 * ⁠ |      or     |
 * "0111"        "0111"
 * Note that only one of the two unmatched 1s is counted as a cow since the
 * non-bull digits can only be rearranged to allow one 1 to be a bull.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: secret = "1", guess = "0"
 * Output: "0A0B"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: secret = "1", guess = "1"
 * Output: "1A0B"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret and guess consist of digits only.
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Straightforward counting
 * Check for each index, how many characters are match, that's bulls/A.
 * For cows/B, for each unmatched character in secret, count how many are there
 * in guess.
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, unordered_set<int>> digit_index;
        for (int i = 0; i < secret.size(); i++) {
            char c = secret[i];
            digit_index[c].insert(i);
        }
        unordered_map<char, int> possible_cows;
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.size(); i++) {
            char c = guess[i];
            if (digit_index.find(c) != digit_index.end()) {
                if (digit_index[c].find(i) != digit_index[c].end()) {
                    bulls++;
                    digit_index[c].erase(i);
                }
                else
                    possible_cows[c]++;
                
            }
        }
        for (auto item : digit_index) {
            char c = item.first;
            auto idx = item.second;
            if (possible_cows.find(c) != possible_cows.end()) {
                cows += min(possible_cows[c], (int)idx.size());
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
// @lc code=end

