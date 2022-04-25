#include<iostream>
using namespace std;

int partition(int a[],int low,int high);
void quickSort(int a[],int low,int high);
void show(int a[],int n);

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    show(a,n);
    quickSort(a,0,n-1);
    show(a,n);
    return 0;
}
void quickSort(int a[],int low,int high){
    if(low<high){
        int pivotpos=partition(a,low,high);
        quickSort(a,low,pivotpos-1);
        quickSort(a,pivotpos+1,high);
    }
}

int partition(int a[],int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot) high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void show(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
