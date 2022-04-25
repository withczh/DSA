#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT16_MAX;
        int maxPrice=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            if(maxPrice<(prices[i]-minPrice)){
                maxPrice=prices[i]-minPrice;
            }
        }
        return maxPrice;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    int n,m,result;
    cout<<"sizeof array:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    result=s.maxProfit(v);
    cout<<"max profit:"<<result<<endl;
    return 0;
}