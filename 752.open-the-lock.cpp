/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 *
 * https://leetcode.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (52.01%)
 * Likes:    1251
 * Dislikes: 47
 * Total Accepted:    74K
 * Total Submissions: 141.8K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can
 * rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
 * to be '9'. Each move consists of turning one wheel one slot.
 * 
 * The lock initially starts at '0000', a string representing the state of the
 * 4 wheels.
 * 
 * You are given a list of deadends dead ends, meaning if the lock displays any
 * of these codes, the wheels of the lock will stop turning and you will be
 * unable to open it.
 * 
 * Given a target representing the value of the wheels that will unlock the
 * lock, return the minimum total number of turns required to open the lock, or
 * -1 if it is impossible.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
 * "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * would be invalid,
 * because the wheels of the lock become stuck after the display becomes the
 * dead end "0102".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * Output: -1
 * Explanation:
 * We can't reach the target without getting stuck.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= deadends.length <= 500
 * deadends[i].length == 4
 * target.length == 4
 * target will not be in the list deadends.
 * target and deadends[i] consist of digits only.
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
struct state_t {
    string code;
    int level;
    state_t(): code(""), level(0) {};
    state_t(const string &code, int level): code(code), level(level) {};
    bool operator==(const state_t &other) const {
        return this->code == other.code;
    }
};
namespace std {
    template<> struct hash<state_t> {
        public:
        size_t operator()(const state_t &s) const{
            return str_hash(s.code);
        }
        private:
        std::hash<std::string> str_hash;
    };
}

/**
 * Find the least spins, so we can think of BFS
 * THe difficult part is how to define the state extending part. 
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<state_t> q;
        unordered_set<state_t> visited;
        unordered_set<string> deadset;
        for (string s : deadends) {
            if (s == "0000") return -1;
            deadset.insert(s);
        }
        
        auto state_is_valid = [&](const state_t &s) {
            return deadset.find(s.code) == deadset.end();
        };
        
        auto state_is_target = [&](const state_t &s) {
            return s.code == target;
        };
        
        auto state_extend = [&](const state_t &s) {
            unordered_set<state_t> result;
            for (int i = 0; i < s.code.size(); i++) {
                string code = s.code;
                char c = code[i];
                string new_code1(code), new_code2(code);
                if (c != '9') new_code1[i] = c+1;
                else new_code1[i] = '0';
                if (c != '0') new_code2[i] = c-1;
                else new_code2[i] = '9';
                
                state_t new_state1(new_code1, s.level+1);
                state_t new_state2(new_code2, s.level+1);
                if (state_is_valid(new_state1) && visited.find(new_state1) == visited.end()) {
                    result.insert(new_state1);
                }
                if (state_is_valid(new_state2) && visited.find(new_state2) == visited.end()) {
                    result.insert(new_state2);
                }
            }
            return result;
        };
        
        state_t start_state("0000", 0);
        q.push(start_state);
        visited.insert(start_state);
        while (!q.empty()) {
            const auto state = q.front();
            q.pop();
            
            if (state_is_target(state)) {
                return state.level;
            }
            
            const auto& new_states = state_extend(state);
            for (const auto &new_state : new_states) {
                q.push(new_state);
                visited.insert(new_state);
            }
        }
        return -1;
    }
};
// @lc code=end

