
#include<iostream>
using namespace std;
void reverse(int a[],int start,int end){
    while(start<end){
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
void rotation(int a[],int d,int n){
    if(d==0) return;
    d=d%n;

    //右移
    reverse(a,0,n-d-1); 
    reverse(a,n-d,n-1);

    // //左移
    // reverse(a,0,d-1);
    // reverse(a,d,n-1);
    
    reverse(a,0,n-1);
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        rotation(a,d,n);
        printArray(a,n);
    }
    return 0;
}