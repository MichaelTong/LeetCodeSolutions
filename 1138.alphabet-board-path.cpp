/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 *
 * https://leetcode.com/problems/alphabet-board-path/description/
 *
 * algorithms
 * Medium (48.68%)
 * Likes:    265
 * Dislikes: 87
 * Total Accepted:    18.2K
 * Total Submissions: 36.7K
 * Testcase Example:  '"leet"'
 *
 * On an alphabet board, we start at position (0, 0), corresponding to
 * character board[0][0].
 * 
 * Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown
 * in the diagram below.
 * 
 * 
 * 
 * We may make the following moves:
 * 
 * 
 * 'U' moves our position up one row, if the position exists on the board;
 * 'D' moves our position down one row, if the position exists on the
 * board;
 * 'L' moves our position left one column, if the position exists on the
 * board;
 * 'R' moves our position right one column, if the position exists on the
 * board;
 * '!' adds the character board[r][c] at our current position (r, c) to the
 * answer.
 * 
 * 
 * (Here, the only positions that exist on the board are positions with letters
 * on them.)
 * 
 * Return a sequence of moves that makes our answer equal to target in the
 * minimum number of moves.  You may return any path that does so.
 * 
 * 
 * Example 1:
 * Input: target = "leet"
 * Output: "DDR!UURRR!!DDD!"
 * Example 2:
 * Input: target = "code"
 * Output: "RR!DDRR!UUL!R!"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target.length <= 100
 * target consists only of English lowercase letters.
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * If the next character is 'z', we need to move horizontally first, then
 * vertically. 
 * Otherwise, we move vertically first, then horizontally. (in case the previous
 * one is 'z')
 * 
 */
class Solution {
private:
    map<char, vector<int>> hash;
    
    void populate_hash() {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int p = ch - 'a';
            hash[ch] = {p / 5, p % 5};
        }
    }

public:
    string alphabetBoardPath(string target) {
        string result;
        char last = 'a';

        populate_hash();
        for (char ch : target) {
            auto &v = hash[ch];
            auto &u = hash[last];
            int dx = u[0] - v[0];
            int dy = u[1] - v[1];
            if (ch == 'z') {
                if (dy > 0) result.append(dy, 'L');
                else result.append(abs(dy), 'R');
                if (dx > 0) result.append(dx, 'U');
                else result.append(abs(dx), 'D');
            } else {
                if (dx > 0) result.append(dx, 'U');
                else result.append(abs(dx), 'D');
                if (dy > 0) result.append(dy, 'L');
                else result.append(abs(dy), 'R');
            }
            result.push_back('!');
            last = ch;
        }
        return result;
    }
};
// @lc code=end

