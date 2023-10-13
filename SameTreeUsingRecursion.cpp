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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if(p==NULL&&q==NULL)
        {
            return true;
        }

        if(q==NULL||p==NULL)
        {
            return false;
        }
        
        if(p->val!=q->val)
        {
            return false;
        }


        //recursive case

       
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);      //for multiple cases but one return statement
         
    }
};