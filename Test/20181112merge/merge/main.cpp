#include <iostream>

using namespace std;

int sortProcess(int arr[],int L,int R);
void merge(int arr[],int L,int m,int R);


void mergeSort(int arr[],int length){
    if(length<2){
        return ;
    }
    sortProcess(arr,0,length-1);
}
int sortProcess(int arr[],int L,int R){
    if(L==R){
        return arr[L];
    }
    int mid=(L+R)/2;
    sortProcess(arr,L,mid);
    sortProcess(arr,mid+1,R);
    merge(arr,L,mid,R);
}
void merge(int arr[],int L,int m,int R){
    int length=R-L+1;
    int help[length];
    int i=0;
    int p1=L;
    int p2=m+1;
    while(p1<=m && p2<=R){
        help[i++]=arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=m){
        help[i++]=arr[p1++];
    }
    while(p2<=R){
        help[i++]=arr[p2++];
    }
    for(i=0;i<length;i++){
        arr[L+i]=help[i];
    }
}
void print_array(int arr[],int length){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[]={7,8,9,1,2,4,5,6,11,22,111,43,235,66,77,88,99,100};
    int length=sizeof(arr)/sizeof(int);
    print_array(arr,length);
    cout<<"*****************"<<endl;

    mergeSort(arr,length);
    print_array(arr,length);
    cout << "Hello world!" << endl;
    return 0;
}
