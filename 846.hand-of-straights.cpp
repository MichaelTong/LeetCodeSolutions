/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (54.55%)
 * Likes:    803
 * Dislikes: 86
 * Total Accepted:    57.7K
 * Total Submissions: 105K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has a hand of cards, given as an array of integers.
 * 
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 * 
 * Return true if and only if she can.
 * 
 * Note: This question is the same as 1296:
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Count the appearances of each number in a treemap(map)
 * Then from the smallest number, reduce their counts.
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> count;
        for (int card : hand) {
            if (count.find(card) == count.end()) {
                count[card] = 1;
            } else
                count[card]++;
        }
        
        while (count.size() > 0) {
            int first = count.begin()->first;
            for (int i = first; i < first + W; i++) {
                if (count.find(i) == count.end()) return false;
                int c = count[i];
                if (c == 1) count.erase(i);
                else count[i]--;
            }
        }
        return true;
    }
};
// @lc code=end

