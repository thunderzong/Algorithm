#include<iostream>

using namespace std;
void printEdge(int *array,int a,int b,int c,int d,int row,int col);
void span_print_array(int *array,int row ,int col){
    int a=0;
    int b=0;
    int c=row-1;
    int d=col-1;
    while(a<=c&&b<=d){
        printEdge(array,a++,b++,c--,d--,row,col);
    }
}
void printEdge(int *array,int a,int b,int c,int d,int row,int col){
    if(a==c){
        for(int i=b;i<=d;i++){
            cout<<*(array+col*a+i)<<"\t";
        }
        cout<<endl;
    }else if(b==d){
        for(int i=a;i<=c;i++){
            cout<<*(array+i*col+b)<<"\t";
        }
        cout<<endl;
    }else{
        int i=a,j=b;
        for(;j<=d;j++){
            cout<<*(array+a*col+j)<<"\t";
        }
        cout<<endl;
        for(i=a+1;i<=c;i++){
            cout<<*(array+i*col+d)<<"\t";
        }
        cout<<endl;
        for(j=d-1;j>=b;j--){
            cout<<*(array+c*col+j)<<"\t";
        }
        cout<<endl;
        for(i=c-1;i>a;i--){
            cout<<*(array+i*col+b)<<"\t";
        }
        cout<<endl;
    }
}
void print_array(int *array,int row,int col){
    cout<<array<<"***********"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<*(array+i*col+j)<<endl;
        }
    }
}
int main(){
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printEdge(*arr,0,0,0,3,4,4);
    cout<<"=================="<<endl;
    printEdge(*arr,0,0,3,0,4,4);
    cout<<"=================="<<endl;
    span_print_array(*arr,4,4);
    cout<<*arr<<"*********"<<endl;
    print_array(*arr,4,4);
    return 1;
}
