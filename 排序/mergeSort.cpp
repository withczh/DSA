#include<iostream>
using namespace std;

class Solution{
    public:
    void mergeSort(int a[],int l,int r){
        if(l<r){
            int mid = l+(r-l)/2;
            mergeSort(a,l,mid);
            mergeSort(a,mid+1,r);
            merge(a,l,mid,r);
        }
    }
    void merge(int a[],int l,int m,int r){
        int i,j,k;
        int n1=m-l+1;
        int n2=r-m;
        int arrayOne[n1],arrayTwo[n2];
        for(i=0;i<n1;i++){
            arrayOne[i]=a[l+i];
        }
        for(j=0;j<n2;j++){
            arrayTwo[j]=a[m+1+j];
        }

        i=0,j=0,k=l;
        while(i<n1&&j<n2){
            if(arrayOne[i]<=arrayTwo[j]){
                a[k++]=arrayOne[i];
                i++;
            }
            else{
                a[k++]=arrayTwo[j];
                j++;
            }
        }
        while(i<n1){
            a[k++]=arrayOne[i];
            i++;
        }
        while(j<n2){
            a[k++]=arrayTwo[j];
            j++;
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
    s.mergeSort(a,0,n-1);
    s.show(a,n);
    return 0;
}