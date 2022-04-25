#include<iostream>
using namespace std;
#include<vector>
#include<stack>

typedef struct BFStree
{
    int val;
    struct BFStree *left;
    struct BFStree *right;
}TreeNode;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;
        TreeNode *p=root,*tmp,*r;
        r=NULL;
        while(p!=NULL||!s.empty()){
            if(p){
                s.push(p);
                p=p->left;
            }
            else{
                tmp=s.top();
                if(tmp->right&&tmp->right!=r){
                    p=tmp->right;
                }
                else{
                    res.push_back(tmp->val);
                    s.pop();
                    r=tmp;
                    p=NULL;
                }
            }
        }
        return res;
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
    vector<int> result;
    Solution s;
    TreeNode* t;
    makeTree(t);
    result=s.postorderTraversal(t);
    for(int n:result){
        cout<<n<<endl;
    }
    return 0;
}