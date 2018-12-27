#include <iostream>
#include    <string>
using namespace std;
int merge(int arr[],int L,int mid,int R);
int mergeProcess(int arr[],int L,int R){
    if(L==R){
        return arr[L];
    }
    int mid=L+(R-L)/2;
    int left=mergeProcess(arr,L,mid);
    int right=mergeProcess(arr,mid+1,R);
    int last=merge(arr,L,mid,R);
    return left+right+last;

}
int merge(int arr[],int L,int mid,int R){
    int length=R-L+1;
    int help[length];
    int count_L=L;
    int count_R=mid+1;
    int i=0;
    int res=0;
    for( i=0;i<length && count_L<=mid && count_R<=R;i++){
        res+=arr[count_L]<arr[count_R]?(R-count_R+1)*arr[count_L]:0;
        help[i]=(arr[count_L]>arr[count_R])? arr[count_R++]:arr[count_L++];
    }
    while(count_L<=mid){
        help[i++]=arr[count_L++];
    }
    while(count_R<=R){
        help[i++]=arr[count_R++];
    }
    for(int i=0;i<length;i++){
        arr[L+i]=help[i];
    }
    return res;
}
void print_array(int arr[],int length){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[]={4,3,2,6,7,8,9,1,22,11,33,99,10};
    int length=sizeof(arr)/sizeof(int);
    print_array(arr,length);
    cout<<("*********")<<endl;
    int res=mergeProcess(arr,0,length-1);
    print_array(arr,length);
    cout<<res<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
