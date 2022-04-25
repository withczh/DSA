#include<iostream>
#include<limits.h>
using namespace std;
#include<stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        long long pre = (long long)INT_MIN-1;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                if(root->val<=pre){
                    return false;
                }
                pre=root->val;
                root=root->right;
            }
        }
        return true;

    }
};

// void BST_insert(TreeNode*& T,int key){
//     if(T==NULL){
//         T=new TreeNode;
//         T->val=key;
//         T->left=T->right=NULL;
//     }
//     else if(T->val>key){
//         BST_insert(T->left,key);
//     }
//     else{
//         BST_insert(T->right,key);
//     }
// }

// void BST_creat(TreeNode*& T){
//     int n;
//     cin>>n;
//     while(n!=999){
//         BST_insert(T,n);
//         cin>>n;
//     }
// }
void inOrder(TreeNode* T){
    if(T!=NULL){
        inOrder(T->left);
        cout<<T->val<<endl;
        inOrder(T->right);
    }
}
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
    TreeNode* t=NULL;
    makeTree(t);
    inOrder(t);
    Solution s;
    if(s.isValidBST(t)){
        cout<<"BST"<<endl;
    }
    else{
        cout<<"not BST"<<endl;
    }
    return 0;
}