//33. 搜索旋转排序数组
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target&&nums[mid]>target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<target&&target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums;
    int num,i,n,result,target;
    printf("input the size of num:\n");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        cin>>n;
        nums.push_back(n);
    }
    printf("the target is :\n");
    cin>>target;
    Solution s;
    result=s.search(nums,target);
    printf("%d\n",result);
    return 0;
}