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
    int search(vector<int> &inorder, int left, int right, int val){
        for(int i=left;i<=right;i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int> & postorder, int left, int right, int &postIdx){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int rootIdx = search(inorder, left,right, postorder[postIdx]);
        postIdx--;

        root->right = helper(inorder, postorder, rootIdx+1,right, postIdx);
        root->left = helper(inorder, postorder, left, rootIdx-1, postIdx); 

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;

        return helper(inorder, postorder, 0, inorder.size()-1,postIdx);
    }
};