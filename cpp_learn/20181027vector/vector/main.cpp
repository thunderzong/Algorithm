#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //vector<vector<int>>array(3);
    vector<vector<int>> array(3,vector<int>(3));
//    for(int i=0;i<3;i++){
//        array[i].resize(3);
//    }
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++)
        array[i][j] = (i*j);
    }
    for (int i = 0; i <3; i++) {
        for (int j = 0; j <3; j++)
        cout <<array[i][j] << "   ";
        cout <<endl;
    }

    int length=10;
    int arr[length];
    string b[length];
    cout<<"***************"<<endl;
    for(auto it1=array.begin();it1!=array.end();it1++){
        for(auto it2=(*it1).begin();it2!=(*it1).end();it2++){
            cout<<*it2<<endl;
        }
    }



    cout << "Hello world!" << endl;
    return 0;
}
