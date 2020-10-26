/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.11%)
 * Likes:    3783
 * Dislikes: 163
 * Total Accepted:    830.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [2,1]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 * 
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
class Solution {
    vector<int> ret;
public:
    /**
     * iterative way to do this with stack
     * (just explicitly use a stack to simulate recursion)
     */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        TreeNode *p = root;
        if (root == nullptr) return ret;

        while (!s.empty() || p != nullptr) {
            if (p != nullptr) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        return ret;
    }
    /**
     * classical way to do this in recursion
     */
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> left = inorderTraversalRecursive(root->left);
        ret.push_back(root->val);
        vector<int> right = inorderTraversalRecursive(root->right);
        return ret;
    }
};
// @lc code=end

