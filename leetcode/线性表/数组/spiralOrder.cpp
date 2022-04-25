//leetcode 54.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }

        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        int elements=matrix.size()*matrix[0].size();

        while(elements>0){
            
            for(int j=left;j<=right&&elements>0;j++){
                res.push_back(matrix[top][j]);
                elements--;
            }
            top++;

            for(int i=top;i<=bottom&&elements>0;i++){
                res.push_back(matrix[i][right]);
                elements--;
            }
            right--;

            for(int j=right;j>=left&&elements>0;j--){
                res.push_back(matrix[bottom][j]);
                elements--;
            }
            bottom--;

            for(int i=bottom;i>=top&&elements>0;i--){
                res.push_back(matrix[i][left]);
                elements--;
            }
            left++;

        }
        return res;
        
    }
};

void buildVector(vector<vector<int>>& matrix){
    
    cout<<"build matrix:"<<endl;
    for(unsigned int i=0;i<matrix.size();i++){
        for(unsigned int j=0;j<matrix[0].size();j++){
            cin>>matrix[i][j];
        }
    }
}

int main(){
    Solution s;
    int m,n;
    cout<<"print the m and n:"<<endl;
    cin>>m>>n;
    vector<vector<int> > matrix(m,vector<int>(n,0));
    buildVector(matrix);
    vector<int> res;
    res=s.spiralOrder(matrix);
    
    for(int val:res){
        cout<<val<<" ";
    }

    return 0;
}