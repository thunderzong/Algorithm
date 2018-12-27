#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int arr[],int i,int j);
int * partition(int arr[],int L,int R);
void quickSort(int arr[],int L,int R){
    if(L<R){
        int *p=partition(arr,L,R);
        quickSort(arr,L,p[0]-1);
        quickSort(arr,p[1]+1,R);
        free(p);
    }

}
int * partition(int arr[],int L,int R){
    int less=L-1;
    int more=R;
    while(L<more){
        if(arr[L]<arr[R]){
            swap(arr,++less,L++);
        }else if(arr[L]>arr[R]){
            swap(arr,--more,L);
        }else{
            L++;
        }
    }
    swap(arr,more,R);
    int *p=(int *)malloc(sizeof(int)*2);
    p[0]=less+1;
    p[1]=more;
    return p;
}
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void print_array(int arr[],int length){

    for(int i=0;i<length;i++){
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[]={4,1,3,56,2,33,77,1,11,22,99,20,40,10,3,4,6,7,7};
    int length=sizeof(arr)/sizeof(int);
    print_array(arr,length);

    //int *p=partition(arr,0,length-1);
    cout<<"****"<<endl;
    quickSort(arr,0,length-1);
    print_array(arr,length);
    cout << "Hello world!" << endl;
    return 0;
}
