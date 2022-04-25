/*
class Solution {
public:
  
    vector<int> preorderTraversal(TreeNode* root) {    
        vector<int> result;
        stack<TreeNode* > s;
        while(root!=NULL||!s.empty()){
            if(root){
                result.push_back(root->val);
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top()->right;
                s.pop();
            }
        }
        return result;
    }
   
};
*/