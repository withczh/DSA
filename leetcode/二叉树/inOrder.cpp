/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;
        while(root!=NULL||!s.empty()){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                res.push_back(s.top()->val);
                root=s.top()->right;
                s.pop();
            }
        }
        return res;
    }
};
*/