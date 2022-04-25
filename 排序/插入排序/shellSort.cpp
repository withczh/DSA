#include<iostream>
using namespace std;

void shellSort(int a[],int n);
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
    shellSort(a,n);
    show(a,n);
    return 0;
}

void shellSort(int a[],int n){
    if(n<=1) return;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int tmp=a[i];
            int j;
            for(j=i;j>=gap&&a[j-gap]>tmp;j-=gap){
                a[j]=a[j-gap];
            }
            a[j]=tmp;
        }
    }
}
void show(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}