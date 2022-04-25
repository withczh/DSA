#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct BFStree
{
    int val;
    struct BFStree *left;
    struct BFStree *right;
}TreeNode;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root) return result;
        queue<TreeNode* > q;
        TreeNode *p=root;
        q.push(p);
        while(!q.empty()){
            vector<int> re;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                re.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(re);
        }
        return result;
    }
};
void makeTree(TreeNode*& T){
    int n;
    cin>>n;
    if(n==0){
       T=NULL;
        return;
    }
    else{
    
        T=new TreeNode;
        T->val=n;
        makeTree(T->left);
        makeTree(T->right);
    }
}
void firstRetrieve(TreeNode*& T){
    if(T!=NULL){
        cout<<T->val<<" ";
        firstRetrieve(T->left);
        firstRetrieve(T->right);
    }
}
int main()
{
    Solution s;
    TreeNode *T;
    vector<vector<int> > r;
    makeTree(T);
    r=s.levelOrder(T);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout<<r[i][j]<<" ";
        }
    }
    return 0;
}