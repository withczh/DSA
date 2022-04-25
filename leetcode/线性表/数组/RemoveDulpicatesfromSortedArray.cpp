/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
**/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret=0;
        if(nums.size()==0) return 0;
        for(unsigned int i=1;i<nums.size();i++){
            if(nums[i]!=nums[ret]){
                nums[++ret]=nums[i];
            }
        }
        
        return ret+1;
    }
};
int main()
{
    vector<int> nums;
    int num,i,n,result;
    printf("input the size of num:\n");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        cin>>n;
        nums.push_back(n);
    }
    printf("the old array is :\n");
    for(unsigned int i=0;i<nums.size();i++){
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    Solution s;
    result=s.removeDuplicates(nums);
    printf("the new array is :\n");
    for( int i=0;i<result;i++){
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    printf("the size of new array is %d\n",result);
    return 0;
}