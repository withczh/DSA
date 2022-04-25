#include<iostream>
using namespace std;

void selectSort(int a[],int n);
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
    selectSort(a,n);
    show(a,n);
    return 0;
}

void selectSort(int a[],int n){
    int min_index;
    for(int i=0;i<n-1;++i){
        min_index=i;
        for(int j=i+1;j<n;++j){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        swap(a[i],a[min_index]);
    }
}

void show(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}