#include<iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1,p2;
        if(!findPath(root,p1,p)||!findPath(root,p2,q)) return NULL;
        int k;
        for(int i=0;i<p1.size()&&i<p2.size();i++){
            if(p1[i]!=p2[i]){
                k=i;
                break;
            }
               
        }
        cout<<p1[k-1]->val<<endl;
        return p1[k-1];

    }
    bool findPath(TreeNode*& root,vector<TreeNode*>& ph,TreeNode*& T ){
        if(!root) return false;
        ph.push_back(root);
        if(root->val==T->val) return true;
        if((root->left)&&(findPath(root->left,ph,T))||(root->right)&&findPath(root->right,ph,T))
           return true;
        ph.pop_back();
        return false;
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
    TreeNode* T,*result,*p,*q;
    int m,n;
    makeTree(T);
    Solution S;
    cin>>m;
    cin>>n;
    p=new TreeNode;
    q=new TreeNode;
    p->val=m;
    q->val=n;
    result=S.lowestCommonAncestor(T,p,q);
    cout<<"commonAncestor:"<<result->val<<endl;
    return 0;
}