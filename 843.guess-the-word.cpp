/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 *
 * https://leetcode.com/problems/guess-the-word/description/
 *
 * algorithms
 * Hard (46.46%)
 * Likes:    627
 * Dislikes: 668
 * Total Accepted:    58.5K
 * Total Submissions: 126K
 * Testcase Example:  '"acckzz"\n["acckzz","ccbazz","eiowzz","abcczz"]\n10'
 *
 * This problem is an interactive problem new to the LeetCode platform.
 * 
 * We are given a word list of unique words, each word is 6 letters long, and
 * one word in this list is chosen as secret.
 * 
 * You may call master.guess(word) to guess a word.  The guessed word should
 * have type string and must be from the original list with 6 lowercase
 * letters.
 * 
 * This function returns an integer type, representing the number of exact
 * matches (value and position) of your guess to the secret word.  Also, if
 * your guess is not in the given wordlist, it will return -1 instead.
 * 
 * For each test case, you have 10 guesses to guess the word. At the end of any
 * number of calls, if you have made 10 or less calls to master.guess and at
 * least one of these guesses was the secret, you pass the testcase.
 * 
 * Besides the example test case below, there will be 5 additional test cases,
 * each with 100 words in the word list.  The letters of each word in those
 * testcases were chosen independently at random from 'a' to 'z', such that
 * every word in the given word lists is unique.
 * 
 * 
 * Example 1:
 * Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
 * 
 * Explanation:
 * 
 * master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
 * master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6
 * matches.
 * master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
 * master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
 * master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
 * 
 * We made 5 calls to master.guess and one of them was the secret, so we pass
 * the test case.
 * 
 * 
 * Note:  Any solutions that attempt to circumvent the judge will result in
 * disqualification.
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
/**
 * We can guess that having less words in the word list is generally better. If
 * the data is random, we can reason this is often the case. 
 * 
 * Now let's use the strategy of making the guess that minimizes the maximum
 * possible size of the resulting word list. If we started with NN words in our
 * word list, we can iterate through all possibilities for what the secret could
 * be.
 * 
 * Store H[i][j] as the number of matches of wordlist[i] and wordlist[j]. For
 * each guess that hasn't been guessed before, do a minimax as described above,
 * taking the guess that gives us the smallest group that might occur. 
 */

class Solution {
    vector<vector<int>> H;
    // The purpose of solve is to find the best guess
    // the best guess can't be in used.
    int solve(const unordered_set<int> &possible, const unordered_set<int> &used) {
        if (possible.size() <= 2) return *(possible.begin());
        unordered_set<int> ansgrp = possible;
        int ansguess = -1;
        // for each unused words among all the words, group the possible words
        // by matches (0-6) to this candidate words.
        // The larger the group, the larger possiblity that it is the secret.
        // After that, among all the words, we want a word that can most reduce
        // the possible words set.
        for (int guess = 0; guess < H.size(); guess++) {
            if (used.find(guess) == used.end()) {
                vector<unordered_set<int>> groups(7, unordered_set<int>());
                for (int j : possible)
                    if (j != guess)
                        groups[H[guess][j]].insert(j);
                int max_group_index = 0;
                for (int i = 0; i < 7; i++) {
                    if (groups[i].size() > groups[max_group_index].size())
                        max_group_index = i;
                }
                
                if (groups[max_group_index].size() < ansgrp.size()) {
                    ansgrp= groups[max_group_index];
                    ansguess = guess;
                }
            }
        }
        return ansguess;
    }
public:
    void findSecretWord(vector<string> wordlist, Master& master) {
        int N = wordlist.size();
        H = vector<vector<int>>(N, vector<int>(N, 0));
        // H stores all the number of matches between each pair of words
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int match = 0;
                for (int k = 0; k < 6; k++) {
                    if (wordlist[i][k] == wordlist[j][k])
                        match++;
                }
                H[i][j] = H[j][i] = match;
            }
        }
        
        unordered_set<int> possible;
        unordered_set<int> used;
        // Initially, all the words are possible
        for (int i = 0; i < N; i++) possible.insert(i);
        
        while (!possible.empty()) {
            // From the possible words and used words, find a guess
            int guess = solve(possible, used);
            int matches = master.guess(wordlist[guess]);
            if (matches == wordlist[0].size()) return;

            // not a full match, we build a new possible word list
            unordered_set<int> possible2;
            for (int j : possible)
                if (H[guess][j] == matches)
                    possible2.insert(j);
            possible = possible2;
            used.insert(guess);
        }
        
    }
};
// @lc code=end

