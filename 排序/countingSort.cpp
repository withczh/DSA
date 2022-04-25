#include<iostream>
using namespace std;

class Solution{
    private:
    int max;
    int *c;
    int *r;
    
    public:
    void countingSorting(int a[],int n){
        if(n<=1) return;
        
        max=a[0];
        for(int i=0;i<n;i++){
            if(max<a[i]){
                max=a[i];
            }
        }

        c=new int[max+1];
        for(int i=0;i<=max;i++){
            c[i]=0;
        }

        //统计次数
        for(int i=0;i<n;++i){
            c[a[i]]++;
        }

        //有序和
        for(int i=1;i<=max;i++){
            c[i]=c[i-1]+c[i];
        }

        r=new int[n];
        //为了维持稳定性，从后往前
        for(int i=n-1;i>=0;--i){
            int index=c[a[i]]-1;
            r[index]=a[i];
            c[a[i]]--;
        }

        for(int i=0;i<n;i++){
            a[i]=r[i];
        }

    }
    void show(int a[],int n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    ~Solution(){
        delete c;
        delete r;
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
    s.countingSorting(a,n);
    s.show(a,n);
    return 0;
}