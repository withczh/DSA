#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int result[m+n];
        int i=0,j=0,k=0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                result[k++]=nums1[i];
                i++;
            }
            else{
                result[k++]=nums2[j];
                j++;
            }
        }
        while(i<m){
            result[k++]=nums1[i];
            i++;
        }
        while(j<n){
            result[k++]=nums2[j];
            j++;
        }
        nums1.clear();
        for(int l=0;l<k;l++){
            nums1.push_back(result[l]);
        }
    }
};
int main()
{   
    vector<int> nums1,nums2;
    int m,n,input;
    cin>>m;
    cin>>n;
    for(int i=0;i<m+n;i++){
        cin>>input;
        nums1.push_back(input);
    }
    for(int i=0;i<n;i++){
        cin>>input;
        nums2.push_back(input);
    }
    Solution s;
    s.merge(nums1,m,nums2,n);
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    return 0;
}