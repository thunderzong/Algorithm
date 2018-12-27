#include <iostream>
#include <cstdlib>
using namespace std;
class ArrayStack{
    public:
    static int index;
    static int size;
    static int *createStack(int initSize){
        if(initSize<0){
            cout<<"输入有误"<<endl;
        }
        index=0;
        return (int*)malloc(sizeof(int)*initSize);
    }
    static void push(int arr[],int num){
        if(index>=size){
            return ;
        }
        arr[index++]=num;
    }
    static int pop(int arr[]){
        if(index<=0){
            cout<<"栈中无元素"<<endl;
        }
        return arr[--index];
    }
    static void print_array(int arr[],int length){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<endl;
        }
    }
    };
//静态成员在类外初始化 不能在主函数里初始化
int ArrayStack::index=0;
int ArrayStack::size=10;

int main()
{

    int *p=ArrayStack::createStack(ArrayStack::size);
    ArrayStack::push(p,1);
    ArrayStack::push(p,2);
    ArrayStack::pop(p);
    ArrayStack::push(p,3);
    ArrayStack::print_array(p,ArrayStack::index);
    cout << "Hello world!" << endl;
    return 0;
}
