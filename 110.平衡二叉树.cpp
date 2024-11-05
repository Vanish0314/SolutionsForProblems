/*
 * @Author: Vanish
 * @Date: 2024-11-04 20:02:55
 * @LastEditTime: 2024-11-04 20:42:57
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include <algorithm>
using namespace std;
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
public:
    int height(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        int left_height = height(root->left);
        int right_height = height(root->right);

        return abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end

