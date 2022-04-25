//leetcode 59.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n,vector<int>(n,0));
        if(n==1){
            result[0][0]=1;
            return result;
        }
        int startx=0;
        int starty=0;
        int loop=n/2;
        int offset=1;
        int mid=n/2;
        int count=1;
        int i,j;
        while(loop--){
            i=startx;
            j=starty;
            
            for(j=starty;j<starty+n-offset;j++){
                result[startx][j]=count++;
            }

            for(i=startx;i<startx+n-offset;i++){
                result[i][j]=count++;
            }

            for(;j>starty;j--){
                result[i][j]=count++;
            }

            for(;i>startx;i--){
                result[i][j]=count++;
            }

            startx++;
            starty++;
            offset+=2;

        }
        if(n%2!=0){
            result[mid][mid]=count;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res=s.generateMatrix(2);
    for(unsigned int i=0;i<res.size();i++){
        for(unsigned int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}