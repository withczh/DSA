#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums){
    bool flag;
    for(unsigned int i=0;i<nums.size()-1;i++){
        flag=false;
        cout<<"第"<<i+1<<"趟"<<endl;
        for(unsigned int j=nums.size()-1;j>i;j--){
            if(nums[j-1]>nums[j]){
                swap(nums[j-1],nums[j]);
                flag=true;
            }
        }
        if(!flag){
            return;
        }
    }
}
void showNums(vector<int> nums){
    for(unsigned int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
}
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    while(n!=999){
        nums.push_back(n);
        cin>>n;
    }
    bubbleSort(nums);
    showNums(nums);
    return 0;
}