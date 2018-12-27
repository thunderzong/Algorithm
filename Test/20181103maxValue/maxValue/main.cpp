#include<iostream>
using namespace std;

int getMaxValue(int arr[],int s,int e){
    if(s==e){
        return arr[s];
    }
    int mid=(s+e)/2;
    int left=getMaxValue(arr,s,mid);
    int right=getMaxValue(arr,mid+1,e);
    return (left>right)     ?    left:right;
}

int main(){
    int arr[]={1,22,33,4,1,11,111,222,334,56,78,88,88,99,567};
    int length=sizeof(arr)/sizeof(int);
    int maxValue=getMaxValue(arr,0,length-1);
    cout<<maxValue<<endl;
    return 1;
}
