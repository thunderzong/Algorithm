#include <iostream>

using namespace std;
void sort(int arr[],int L,int R){
    int temp=arr[L];
    while(L<R){
        while(arr[R]>temp)
            R--;
        arr[L]=arr[R];
        while(arr[L]<temp)
            L++;
        arr[R]=arr[L];
    }
}
void quicksort(int arr[],int L,int R){
    while(L<R){
        quicksort(arr,L,(L+R)/2);
        quicksort(arr,(L+R)/2+1,R);
    }
}

void print_array(int arr[],int length){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<endl;
    }
}

int main()
{

    int arr[]={3,4,5,6,1,2,11,6,23,3,5,6};

    int length=sizeof(arr)/sizeof(int);
    print_array(arr,length);
    quicksort(arr,0,length-1);
    print_array(arr,length);

    cout << "Hello world!" << endl;
    return 0;
}
