/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
//好题 从前序与中序遍历序列构造二叉树

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// @lc code=start

#include<vector>
using namespace std;

class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;

        int length = preorder.size();
        int mid = preorder[0];
        TreeNode *root = new TreeNode(mid);
        
        int index = 0;
        while(mid != inorder[index])
        {
            index++;
        }

        vector<int> leftInorder(inorder.begin(),inorder.begin()+index);
        vector<int> leftPreorder(preorder.begin()+ 1,preorder.begin()+1+index);

        vector<int> rightInorder(inorder.begin()+index+1,inorder.end());
        vector<int> rightPreorder(preorder.begin()+1+index,preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }   
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> pre= {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};

    s.buildTree(pre, in);
}