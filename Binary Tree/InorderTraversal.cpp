
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// recursive (one function)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> left;
        if(!root){
            return left;
        }
        left = inorderTraversal(root->left);
        left.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

// recursive (two function)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, &ans);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int> *ans){
        if(root != NULL){
            helper(root->left, ans);
            ans->push_back(root->val);
            helper(root->right, ans);
        }
    }
};

// iterative(stack)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        while (true){
            while(root){
                st.push(root);
                root = root->left;
            }
            if(st.empty()){
                return ans;
            }
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            root = node->right;
        }
        return ans;
    }
};