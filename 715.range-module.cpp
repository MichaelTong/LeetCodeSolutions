/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 *
 * https://leetcode.com/problems/range-module/description/
 *
 * algorithms
 * Hard (38.89%)
 * Likes:    502
 * Dislikes: 38
 * Total Accepted:    21K
 * Total Submissions: 53.2K
 * Testcase Example:  '["RangeModule","addRange","removeRange","queryRange","queryRange","queryRange"]\n[[],[10,20],[14,16],[10,14],[13,15],[16,17]]'
 *
 * A Range Module is a module that tracks ranges of numbers. Your task is to
 * design and implement the following interfaces in an efficient manner.
 * 
 * addRange(int left, int right) Adds the half-open interval [left, right),
 * tracking every real number in that interval.  Adding an interval that
 * partially overlaps with currently tracked numbers should add any numbers in
 * the interval [left, right) that are not already tracked.
 * 
 * queryRange(int left, int right) Returns true if and only if every real
 * number in the interval [left, right)
 * ⁠is currently being tracked.
 * 
 * removeRange(int left, int right) Stops tracking every real number currently
 * being tracked in the interval [left, right).
 * 
 * Example 1:
 * 
 * addRange(10, 20): null
 * removeRange(14, 16): null
 * queryRange(10, 14): true (Every number in [10, 14) is being tracked)
 * queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not
 * being tracked)
 * queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked,
 * despite the remove operation)
 * 
 * 
 * 
 * Note:
 * A half open interval [left, right) denotes all real numbers left .
 * 
 * 0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
 * The total number of calls to addRange in a single test case is at most 1000.
 * The total number of calls to queryRange in a single test case is at most
 * 5000.
 * The total number of calls to removeRange in a single test case is at most
 * 1000.
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Binary search for ranges, handles range merges and splits
 * 
 */
class RangeModule {
    vector<vector<int>> intervals;
    /**
     * return 0 or postive -> in interval
     * return negative -> before the interval
     *        before 0 -> -1
     *        before 1 -> -2
     *        before last one -> -(n-1) - 1 -> -n
     *        after last one -> -n-1
     */
    int binarySearch(int target) {
        int first = 0, last = intervals.size();
        while (first < last) {
            int mid = (first + last) / 2;
            int begin = intervals[mid][0];
            int end = intervals[mid][1];
            if (target > end) {
                first = mid + 1;
            } else if (target < begin) {
                last = mid;
            } else {
                return mid;
            }
        }
        return -first - 1;
    }
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        int pos_l = binarySearch(left);
        int pos_r = binarySearch(right);
        vector<int> newInterval = {left, right};
        
        if (pos_l >= 0 && pos_l == pos_r) return;
        else if (pos_l <0 && pos_l == pos_r) {
            intervals.insert(intervals.begin() + (-pos_l-1), newInterval);
            return;
        } else {
            if (pos_l >= 0) newInterval[0] = intervals[pos_l][0];
            if (pos_r >= 0) newInterval[1] = intervals[pos_r][1];
            int rm_first = pos_l >= 0? pos_l : -pos_l-1;
            int rm_last = pos_r >= 0? pos_r+1 : -pos_r-1;
            intervals.erase(intervals.begin()+rm_first, intervals.begin()+rm_last);
            intervals.insert(intervals.begin()+rm_first, newInterval);
            return;
        }
    }
    
    bool queryRange(int left, int right) {
        int pos_l = binarySearch(left);
        int pos_r = binarySearch(right);
        if (pos_l >= 0 && pos_l == pos_r) return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        int pos_l = binarySearch(left);
        int pos_r = binarySearch(right);
        
        if (pos_l < 0 && pos_l == pos_r) return;
        else if (pos_l >= 0 && pos_l == pos_r) {
            int rm_l = intervals[pos_l][0];
            int rm_r = intervals[pos_r][1];
            vector<vector<int>> newIntervals;
            if (rm_l != left) {
                newIntervals.push_back(vector<int>{rm_l, left});
            }
            if (rm_r != right) {
                newIntervals.push_back(vector<int>{right, rm_r});
            }
            intervals.erase(intervals.begin() + pos_l);
            intervals.insert(intervals.begin() + pos_l, newIntervals.begin(), newIntervals.end());
        } else {
            int rm_first = pos_l >= 0 ? (pos_l + 1) : (-pos_l-1);
            int rm_last = pos_r >= 0? (pos_r) : (-pos_r-1);
            if (pos_l >= 0) {
                if (intervals[pos_l][0] != left)
                    intervals[pos_l][1] = left;
                else
                    rm_first--;
            }
            if (pos_r >= 0) {
                if (intervals[pos_r][1] != right)
                    intervals[pos_r][0] = right;
                else
                    rm_last++;
            }
            intervals.erase(intervals.begin() + rm_first, intervals.begin()+rm_last);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

