#include <iostream>

using namespace std;
void rorateEdge(int *arr,int a,int b,int c,int d,int row,int col){
    int temp=0;
    for(int i=0;i<d-b;i++){
        temp=*(arr+a*col+b+i);
        //up
        *(arr+a*col+(b+i))=*(arr+(c-i)*col+b);
        //left
        *(arr+(c-i)*col+b)=*(arr+(c*col)+(d-i));
        //down
       *(arr+c*col+(d-i))=*(arr+(a+i)*col+d);
        //right
        *(arr+(a+i)*col+d)=temp;
    }
//    int help[d-b+1];
//    for(int i=0;i<d-b+1;i++){
//        help[i]=*(arr+a*col+b+i);
//    }
//    for(int i=0;i<d-b+1;i++){
//       *(arr+a*col+(b+i))=*(arr+(c-i)*col+b);
//    }
//    for(int i=0;i<d-b+1;i++){
//        *(arr+(a+i)*col+b)=*(arr+(c*col)+(b+i));
//    }
//    for(int i=0;i<d-b+1;i++){
//        *(arr+c*col+(b+i))=*(arr+(c-i)*col+d);
//    }
//     for(int i=0;i<d-b+1;i++){
//        *(arr+(a+i)*col+d)=help[i];
//    }
}
void print_array(int *arr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<*(arr+i*col+j)<<"\t";
        }
        cout<<endl;

    }
}
void rorate_print(int *arr,int row,int col){
    int a=0;
    int b=0;
    int c=row-1;
    int d=col-1;
    while(a<c && b<d){
        rorateEdge(arr,a++,b++,c--,d--,row,col);
        //cout<<"***"<<endl;
    }
}
int main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    print_array(*arr,4,4);
    cout<<"================"<<endl;
    rorate_print(*arr,4,4);
    print_array(*arr,4,4);
    cout << "Hello world!" << endl;
    return 0;
}
