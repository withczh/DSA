#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums){
        int maxSum,result;
        maxSum=nums[0];
        result=maxSum;
        for(int i=1;i<nums.size();i++){
           maxSum=max(maxSum+nums[i],nums[i]);
           if(maxSum>result) result=maxSum;
        }
        return result;
    }
    
};
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums,int& start,int& end,int& allNegative) {
//         int maxSum=0,currentSum=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>=0) allNegative=0;
//         }
//         if(nums.size()==1) return nums[0];
//         if(!allNegative){    
//             for(int i=0;i<nums.size();i++){
//                 currentSum+=nums[i];
//                 if(maxSum<currentSum){
//                     end=i;
//                     maxSum=currentSum;
//                 }
//                 else if(currentSum<0){
//                     currentSum=0;
//                     start=i+1;
//                     end=start;
//                 }
//             }
//         }
//         else{
//             maxSum=nums[0];
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]>maxSum){
//                     maxSum=nums[i];
//                     start=i;
//                 }
//             }
//         }
//             return maxSum;
//     }
// };
// int main()
// {   
//     Solution s;
//     vector<int> num;
//     int max=0,input,n;
//     int start=0,end=0,allNegative=1;
//     cout<<"size of array:"<<endl;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>input;
//         num.push_back(input);
//     }
//     max=s.maxSubArray(num,start,end,allNegative);
//     cout<<"max=:"<<max<<endl;
//     cout<<"subsequence:"<<endl;
//     //不是全为负数的数组
//     if(!allNegative){
//         for(int i=start;i<=end;i++){
//             cout<<num[i]<<" ";
//         }
//         cout<<endl;
//     }
//     else{//全为负数的数组
//         cout<<num[start]<<endl;
//     }
//     return 0;
// }