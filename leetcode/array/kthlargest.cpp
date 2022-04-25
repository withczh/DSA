#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int result;
        result=find(nums,0,nums.size()-1,k);
        return result;
    }
    int find(vector<int>& nums,int low,int high,int k){
        int pivot=nums[low];
        int tmp_low=low;
        int tmp_high=high;
        while(low<high){
            while(low<high&&nums[high]<=pivot) high--;
            nums[low]=nums[high];
            while(low<high&&nums[low]>=pivot) low++;
            nums[high]=nums[low];
        }
        nums[low]=pivot;
        if(low+1==k) return nums[low];
        else if(low+1>k){
            return find(nums,tmp_low,low-1,k);
        }
        else{
            return find(nums,low+1,tmp_high,k);
        }
    }
};
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    while(n!=999){
        nums.push_back(n);
        cin>>n;
    }
    Solution s;
    cout<<s.findKthLargest(nums,3)<<endl;
    return 0;
}