/*直接插入排序
  下标从0开始
  设第一个元素已经排好序，从第二个元素开始，往前比较，找到插入点
  将插入点后的数据往后移并在插入点插入元素
  */
 #include<iostream>
 using namespace std;

 void insertSort(int a[],int n);
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
    insertSort(a,n);
    show(a,n);
    return 0;
}
// //直接插入
// void insertSort(int a[],int n){
//      if(n<=1) return;
//      for(int i=1;i<n;++i){
//          int val=a[i];
//          int j=i-1;
//          for(;j>=0;--j){
//              if(a[j]>val){
//                  a[j+1]=a[j];
//              }
//              else break;
//          }
//          a[j+1]=val;
//      }
//  }
 //折半插入
void insertSort(int a[],int n){
     if(n<=1) return;
     int i,j,low,high,mid;
     for(i=1;i<n;i++){
         int val=a[i];
         low=0,high=i-1;
         while(low<=high){
             mid=low+(high-low)/2;
             if(a[mid]>val) high=mid-1;
             else low=mid+1;
         }
         for(j=i-1;j>=high+1;--j){
             a[j+1]=a[j];
         }
         a[high+1]=val;
     }
 }

 void show(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
 