//删除有序数组中的重复项 II
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret=2;
        if(nums.size()<=2) return nums.size();
        for(unsigned int i=2;i<nums.size();i++){
            if(nums[i]!=nums[ret-2]) {
                nums[ret++]=nums[i];
            }
        }
        return ret;
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