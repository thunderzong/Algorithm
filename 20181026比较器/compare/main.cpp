#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;

void print_array_one(int *array,int length){
    for(int i=0;i<length;i++){
            cout<<*(array+i)<<endl;
    }
}
int * copyArray(int *array,int length){
    int *newArray=(int *)malloc(sizeof(int)*length);
    for(int i=0;i<length;i++){
        *(newArray+i)=*(array+i);
    }
    return newArray;
}
void print_array_two(int *array,int row,int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++)
            cout<<*(array+i*row+j)<<endl;
    }
}
bool arrayIsEqual(int *array1,int *array2,int length){
    for(int i=0;i<length;i++){
        if(*(array1+i)!=*(array2+i)){
            return false;
        }
    }
    return true;
}
void swap(int *array,int i,int j){
    int temp=*(array+i);
    *(array+i)=*(array+j);
    *(array+j)=temp;
}
bool compare(int a,int b){
    return a<b? true :false;
}
int * generateRandomArray(int length){
    srand(time(0));
    //生成一个随机大小的数组
    //int length=rand()%1000;
    int *arr=(int *)malloc(sizeof(int)*length);
    //cout<<arr<<endl;
    //cout<<"length的值为:"<<length<<endl;
    //为这个随机大小数组赋值
//    for(int i=0;i<length;i++){
//        arr[i]=rand()%1000+1;
//        cout<<arr[i]<<"\t"<<arr+i<<endl;
//    }
    //cout<<"************"<<endl;
    return arr;
}
void insertSort(int *array,int length){
    if(length<=1){
        return ;
    }
    for(int i=1;i<length;i++){
        for(int j=i-1;j>=0 && array[j]>array[j+1];j--){
            swap(array,j,j+1);
        }
    }

}
int main()
{
    int TestTimes=10000000;
    bool successful=true;
    for(int i=0;i<TestTimes;i++){
        int length=10;
        int *pointer1=generateRandomArray(length);
        int *pointer2=copyArray(pointer1,length);
//        for(int i=0;i<length;i++){
//            cout<<*(pointer1+i)<<"\t"<<pointer1[i]<<endl;
//        }
        //cout<<"*pointer1的值为："<<*(pointer1)<<endl;
        sort(pointer1,pointer1+length,compare);
        //print_array_one(pointer1,length);
        //cout<<"*****************************************"<<endl;
        insertSort(pointer2,length);
        //print_array_one(pointer2,length);


        //cout<<"**************"<<endl;
        if(!arrayIsEqual(pointer1,pointer2,length)){
            successful=false;
            //cout<<"true"<<endl;
        }
    }

    cout<<(successful ? "Nice" :"Fucking fucked!")<<endl;
    //int array[4]={1,2,3,4};
    //int array2[]
    //print_array_one(array,4);
    //swap(array,2,3);

   // print_array_one(array,4);
    cout << "Hello world!" << endl;
    return 0;




}
