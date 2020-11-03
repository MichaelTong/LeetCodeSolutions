/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (54.80%)
 * Likes:    2884
 * Dislikes: 151
 * Total Accepted:    215.2K
 * Total Submissions: 390K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
#include "lc.hpp"
// @lc code=start
struct MyHeapNode {
    int row;
    int column;
    int value;

    MyHeapNode(int r, int c, int v): row(r), column(c), value(v) {}

};

class MyHeapNodeCompare {
public:
    bool operator()(const MyHeapNode &lhs, const MyHeapNode &rhs) {
        return lhs.value > rhs.value;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        priority_queue<MyHeapNode, vector<MyHeapNode>, MyHeapNodeCompare> minHeap;
        for (int r = 0; r < min(k, N); r++) {
            minHeap.push(MyHeapNode(r, 0, matrix[r][0]));
        }
        int ret;
        while (k) {
            MyHeapNode node = minHeap.top();
            minHeap.pop();
            int r = node.row;
            int c = node.column;
            ret = node.value;
            if (c + 1 < N) {
                minHeap.push(MyHeapNode(r, c+1, matrix[r][c+1]));
            }
            k--;
        }
        return ret;
    }
};
// @lc code=end

