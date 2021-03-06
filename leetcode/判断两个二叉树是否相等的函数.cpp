/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        //防止两个是一棵树。
        if(p == q){
            return true;
        }
        
        if(p != nullptr && q != nullptr){
            if(p->val != q->val){
                return false;
            }
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};
