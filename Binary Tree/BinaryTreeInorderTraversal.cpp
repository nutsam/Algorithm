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
 
 //Time Complexity = O(n)
 //Space Complexity = O(n) 
class Solution {
public:
    //Recusive
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res){
        if(root != NULL){
            if(root->left != NULL){
                helper(root->left, res);
            }
            res.push_back(root->val);
            if(root->right != NULL){
                helper(root->right, res);
            } 
        }
    }*/
    //Iterative + stack
    /*vector<int> inorderTraversal(TreeNode* root){
        
        vector<int> res;
        stack<TreeNode*> stack;
        
        while(root != NULL || !stack.empty()){
            while(root != NULL){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }*/
    //Morris traversal
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        TreeNode* pre;
        while(root != NULL){
            if(root->left == NULL){
                res.push_back(root->val);
                root = root->right;
            }
            else{
                pre = root->left;
                while(pre->right != NULL && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
                
            }
        }
        return res;
    }
    
};
