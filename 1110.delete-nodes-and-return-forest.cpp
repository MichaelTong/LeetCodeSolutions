/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 *
 * https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (67.35%)
 * Likes:    1395
 * Dislikes: 48
 * Total Accepted:    76.8K
 * Total Submissions: 114K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * Given the root of a binary tree, each node in the tree has a distinct
 * value.
 * 
 * After deleting all nodes with a value in to_delete, we are left with a
 * forest (a disjoint union of trees).
 * 
 * Return the roots of the trees in the remaining forest.  You may return the
 * result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * Output: [[1,2,null,4],[6],[7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is at most 1000.
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
 * 
 */
#include "lc.hpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Do a DFS/BFS.
 * 
 * DFS approach, each call tells if the input node needs to be put into forest,
 * and do the deletion.
 * 
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_del;
        to_del.insert(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ret;
        
        if(!doDel(root, to_del, ret))
            ret.push_back(root);
        return ret;
        
    }
    bool doDel(TreeNode* root, const unordered_set<int> &to_del,
              vector<TreeNode*> &forest) {
        if (root == nullptr)
            return true;
        bool delLeft = doDel(root->left, to_del, forest);
        bool delRight = doDel(root->right, to_del, forest);
        if (delLeft)
            root->left = nullptr;
        if (delRight)
            root->right = nullptr;
        if (to_del.find(root->val) != to_del.end()) {
            if (!delLeft)
                forest.push_back(root->left);
            if (!delRight)
                forest.push_back(root->right);
            return true;
        }
        return false;
            
    }
};
// @lc code=end

