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
//递归
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         else{
//             int ld=maxDepth(root->left);
//             int rd=maxDepth(root->right);
//             if(ld>rd){
//                 return ld+1;
//             }
//             else{
//                 return rd+1;
//             }
//         }
//     }
// };
//非递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int depth=0;
        q.push(root);
        while(!q.empty()){
           depth++;
           int size=q.size();
           for(int i=0;i<size;i++){
               auto p=q.front();
               q.pop();
               if(p->left){
                   q.push(p->left);
               }
               if(p->right){
                   q.push(p->right);
               }
           }
        }
        return depth;
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
int main()
{
    Solution s;
    TreeNode *T;
    makeTree(T);
    cout<<"depth of tree is:"<<s.maxDepth(T)<<endl;
    return 0;
}