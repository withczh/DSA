#include<iostream>
using namespace std;

class Solution{
    public:     //对于每个数据从上到下堆化
    void heapify(int a[],int n,int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if (l<n&&a[l]>a[largest])
        {
            largest=l;
        }
        if (r<n&&a[r]>a[largest])
        {
            largest=r;
        }
        if(largest!=i){
            swap(a[i],a[largest]);
            heapify(a,n,largest);
        } 
    }

    void heapSort(int a[],int n){
        if(n<=1) return;
        //从后往前处理数据，从最后一个非叶子节点开始
        for(int i=n/2-1;i>=0;i--){
            heapify(a,n,i);
        }

        //从堆顶取出数据
        for(int i=n-1;i>=0;i--){
            swap(a[0],a[i]);
            heapify(a,i,0);
        }
        

    }

    void show(int a[],int n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    s.heapSort(a,n);
    s.show(a,n);
    return 0;
}