/*
 * @Author: Vanish
 * @Date: 2024-11-04 21:13:36
 * @LastEditTime: 2024-11-05 22:11:56
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

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

// 你嘛21亿的测试用例就tm有病

class Solution {
public:

    bool isValidBST(TreeNode* root,long long min,long long max) 
    {
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        if(!root->left &&!root->right) return true;

        if(!root->left && root->right) 
            return (root->val < root->right->val && isValidBST(root->right,root->val,max));
        if(root->left &&!root->right) 
            return (root->val > root->left->val && isValidBST(root->left,min,root->val));

        if(root->val > root->left->val && root->val < root->right->val)
            return (isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max));
        return false;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left &&!root->right) return true;

        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};
// @lc code=end

