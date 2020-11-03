/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (39.38%)
 * Likes:    296
 * Dislikes: 20
 * Total Accepted:    14.7K
 * Total Submissions: 36.8K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You don't need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [6,1,9]
 * Output: 2
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
struct state_t {
    int idx;
    int level;
    state_t(int idx, int level): idx(idx), level(level) {}
    bool operator==(const state_t &other) const {
        return this->idx == other.idx;
    }
};

namespace std {
    template<> struct hash<state_t> {
    public:
        std::hash<int> int_hash;
        size_t operator()(const state_t& s) const {
            return int_hash(s.idx);
        }
    };
}

/**
 * Find the minimum jumps, use BFS
 * When getting the neighbors, you can jump to i+1, i-1, and all
 * the indexes with the same value. 
 * ! mark them as visited once you add them into exploration queue.
 */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> val_indices;
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            if (val_indices.find(val) == val_indices.end()) {
                val_indices[val] = vector<int>{i};
            } else {
                val_indices[val].push_back(i);
            }
        }
        unordered_set<state_t> visited;
        
        auto state_is_valid = [&](const state_t &s) {
            return s.idx < arr.size() && s.idx >= 0;
        };
        auto state_is_target = [&](const state_t &s) {
            return s.idx == arr.size() - 1;
        };
        auto state_extend = [&](const state_t &s) {
            unordered_set<state_t> result;
            int cur_val = arr[s.idx];
            if (s.idx + 1 < arr.size() && arr[s.idx+1] != cur_val) {
                state_t new_state(s.idx+1, s.level+1);
                if (visited.find(new_state) == visited.end())
                    result.insert(new_state);
            }
            if (s.idx - 1 >= 0 && arr[s.idx-1] != cur_val) {
                state_t new_state(s.idx-1, s.level+1);
                if (visited.find(new_state) == visited.end())
                    result.insert(new_state);
            }
            for (auto nbr : val_indices[cur_val]) {
                if (nbr == s.idx) continue;
                state_t new_state(nbr, s.level+1);
                if (visited.find(new_state) == visited.end())
                    result.insert(new_state);
            }
            return result;
        };
        
        state_t start_state(0, 0);
        queue<state_t> q;
        q.push(start_state);
        visited.insert(start_state);
        
        while (!q.empty()) {
            const auto s = q.front();
            q.pop();
            if (state_is_target(s))
                return s.level;
            
            int cur_val = arr[s.idx];
            if (s.idx + 1 < arr.size() && arr[s.idx+1] != cur_val) {
                state_t new_state(s.idx+1, s.level+1);
                if (visited.find(new_state) == visited.end()){
                    q.push(new_state);
                    visited.insert(new_state);
                }
            }
            if (s.idx - 1 >= 0 && arr[s.idx-1] != cur_val) {
                state_t new_state(s.idx-1, s.level+1);
                if (visited.find(new_state) == visited.end()){
                    q.push(new_state);
                    visited.insert(new_state);
                }
            }
            for (auto nbr : val_indices[cur_val]) {
                if (nbr == s.idx) continue;
                state_t new_state(nbr, s.level+1);
                if (visited.find(new_state) == visited.end()){
                    q.push(new_state);
                    visited.insert(new_state);
                }
            }
            val_indices[cur_val].clear();
        }
        
        return -1;
        
    }
};
// @lc code=end

