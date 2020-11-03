/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (53.13%)
 * Likes:    617
 * Dislikes: 1199
 * Total Accepted:    145.8K
 * Total Submissions: 273.5K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * 
 * 
 */
#include "lc.hpp"
// @lc code=start
class Solution {
    int N;
    vector<int> original;
    vector<int> array;
public:
    Solution(vector<int>& nums) {
        original = nums;
        array = nums;
        N = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < array.size(); i++) {
            int get = (rand()%(N-i)) + i;
            swap(array[i], array[get]);
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

