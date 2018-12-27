#include <iostream>
#include <cstdlib>
using namespace std;
int first=0;
int last=0;
int size=0;
int length=5;
int *createQueue(int initsize){
    if(initsize<1){
        cout<<"create queue failed"<<endl;
    }
    int *p=(int *)malloc(sizeof(int)*initsize);
    first=0;
    last=-1;
}
void push(int arr[],int obj){
    if(size==length){
        cout<<"The queue is empty"<<endl;
    }
    last=(last==length-1)? 0:last+1;
    arr[last]=obj;
    size++;
    //last=(last==length-1)? 0:last+1;

}

int pop(int arr[]){
    if(size<1){
        cout<<"The queue is empty"<<endl;
    }
    int r=arr[first];
    size--;
    first=(first==length-1)? 0:first+1;
    return r;
}
void print_array(int arr[]){
    if(size<1){
        cout<<"The queue is empty"<<endl;
        return ;
    }

    for(int i=first;(i%length)!=last;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    int *p=createQueue(length);
    push(p,10);
    push(p,9);
    push(p,8);
    push(p,7);
    push(p,6);
    //pop(p);
    //push(p,1);
    print_array(p);
    free(p);
    cout << "Hello world!" << endl;
    return 0;
}
